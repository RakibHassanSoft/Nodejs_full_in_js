# Day 50

✅ **আজকের দিনটি: One-to-many with ObjectId**

আজকের দিনে আমরা **One-to-Many relationship** তৈরি করবো, যেখানে একটি ডকুমেন্টের মধ্যে অনেকগুলি সাব-ডকুমেন্ট সম্পর্কিত থাকবে। এটি সাধারণত **ObjectId** ব্যবহার করে MongoDB-তে কার্যকর করা হয়। 

---

## ⏸️ 1. What is One-to-Many Relationship?

একটি **One-to-Many** সম্পর্কের মধ্যে, একটি একক ডকুমেন্ট অন্য অনেক ডকুমেন্টের সাথে সম্পর্কিত থাকে। উদাহরণস্বরূপ, একটি **Author** মডেল হতে পারে যার অনেকগুলি ব্লগ পোষ্ট থাকবে। এখানে **Author** মডেলটি **Blog** মডেলের সাথে সম্পর্কিত থাকে, যেখানে একটি **Author** এর জন্য অনেক **Blog** পোষ্ট থাকতে পারে।

---

## ⏸️ 2. Set up Mongoose Models

### Author Model

প্রথমে **Author** মডেল তৈরি করতে হবে, যেখানে লেখকের নাম এবং ইমেইল থাকবে।

```js
const mongoose = require('mongoose');

const authorSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true
  },
  email: {
    type: String,
    required: true,
    unique: true
  }
});

const Author = mongoose.model('Author', authorSchema);
module.exports = Author;
```

এখানে:
- **Author** মডেলটি লেখকের নাম এবং ইমেইল ধারণ করে।

### Blog Model

এখন **Blog** মডেল তৈরি করতে হবে, যেখানে ব্লগ পোষ্টের শিরোনাম, কনটেন্ট এবং লেখক (author) সম্পর্কিত ObjectId থাকবে।

```js
const mongoose = require('mongoose');

const blogSchema = new mongoose.Schema({
  title: {
    type: String,
    required: true
  },
  content: {
    type: String,
    required: true
  },
  createdAt: {
    type: Date,
    default: Date.now
  },
  author: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'Author',
    required: true
  }
});

const Blog = mongoose.model('Blog', blogSchema);
module.exports = Blog;
```

এখানে:
- **author** ফিল্ডটি **Author** মডেলের **ObjectId** রেফারেন্স ব্যবহার করছে। এটি ব্লগ পোষ্টের সাথে লেখকের সম্পর্ক তৈরি করে।

---

## ⏸️ 3. Create API to Add Blog for an Author

এখন, আমাদের একটি API তৈরি করতে হবে যা একটি ব্লগ পোষ্ট তৈরি করবে এবং লেখক (author) সম্পর্কিত তথ্য সংরক্ষণ করবে।

### Example: Add Blog with Author Reference

```js
const express = require('express');
const mongoose = require('mongoose');
const Author = require('./models/Author');
const Blog = require('./models/Blog');
const app = express();
const port = 3000;

mongoose.connect('mongodb://localhost:27017/blogAPI', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Add Blog Post for an Author
app.post('/blogs', async (req, res) => {
  try {
    const { title, content, authorId } = req.body;

    // Check if the author exists
    const author = await Author.findById(authorId);
    if (!author) {
      return res.status(404).json({ message: 'Author not found' });
    }

    // Create a new blog post with the author reference
    const newBlog = new Blog({
      title,
      content,
      author: authorId
    });

    // Save the new blog post
    await newBlog.save();
    res.status(201).json(newBlog);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- **POST `/blogs`** API এর মাধ্যমে আমরা একটি ব্লগ পোষ্ট তৈরি করতে পারি, যেখানে লেখক (author) এর **ObjectId** প্রেরিত হয়।

---

## ⏸️ 4. Get Blogs for an Author (One-to-Many)

এখন, আমরা একটি API তৈরি করবো যা একটি নির্দিষ্ট লেখকের সাথে সম্পর্কিত সমস্ত ব্লগ পোষ্ট প্রদর্শন করবে। এটি **One-to-Many** সম্পর্কের বাস্তবায়ন।

### Example: Get Blogs by Author

```js
// Get all blogs by a specific author
app.get('/authors/:authorId/blogs', async (req, res) => {
  try {
    const blogs = await Blog.find({ author: req.params.authorId }).populate('author');
    if (blogs.length === 0) {
      return res.status(404).json({ message: 'No blogs found for this author' });
    }
    res.json(blogs);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **GET `/authors/:authorId/blogs`** API লেখকের **`authorId`** দ্বারা সম্পর্কিত সমস্ত ব্লগ পোষ্ট ফেরত দেয়।
- **`populate('author')`** ব্যবহৃত হয়েছে যাতে ব্লগ পোষ্টের লেখকের বিস্তারিত তথ্যও পাওয়া যায়।

---

## ⏸️ 5. Testing the One-to-Many API

এখন, আমাদের তৈরি API গুলি পরীক্ষা করার জন্য **Postman** অথবা **Insomnia** ব্যবহার করতে হবে।

1. **POST `/blogs`** রিকোয়েস্ট পাঠান একটি নতুন ব্লগ পোষ্ট তৈরি করতে:
   - **Request Body:**
     ```json
     {
       "title": "My Second Blog Post",
       "content": "Content for the second blog post.",
       "authorId": "authorObjectIdHere"
     }
     ```

2. **GET `/authors/:authorId/blogs`** রিকোয়েস্ট পাঠান লেখকের সমস্ত ব্লগ পোষ্ট পেতে:
   - **Response:**
     ```json
     [
       {
         "title": "My Second Blog Post",
         "content": "Content for the second blog post.",
         "author": {
           "_id": "authorObjectIdHere",
           "name": "Author Name",
           "email": "author@example.com"
         }
       }
     ]
     ```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **One-to-Many relationship** কিভাবে **MongoDB** এবং **Mongoose** এর মাধ্যমে কার্যকর করা যায়।
- **ObjectId** রেফারেন্স ব্যবহার করে **Blog** মডেলে **Author** মডেলের তথ্য সংযুক্ত করা হয়।
- **populate()** মেথড ব্যবহার করে সম্পর্কিত ডেটা একত্রে ফেরত পাওয়া যায়।

আজকের দিনে আপনি শিখলেন কিভাবে **One-to-Many relationship** বাস্তবায়ন করবেন এবং MongoDB-তে এটি পরিচালনা করবেন। 🎉🚀





# Day 51

✅ **আজকের দিনটি: Populate Comments Inside Post**

আজকের দিনে আমরা শিখবো কিভাবে MongoDB তে ব্লগ পোষ্টের মধ্যে **Comments** পপুলেট করতে হয়। এটি **One-to-Many** সম্পর্কের একটি উন্নত ব্যবহার, যেখানে একটি ব্লগ পোষ্টে একাধিক মন্তব্য (comments) থাকতে পারে। আমরা এই সম্পর্কটি **Mongoose** এর মাধ্যমে বাস্তবায়ন করবো এবং **populate()** ব্যবহার করে মন্তব্যগুলি ব্লগ পোষ্টের মধ্যে অন্তর্ভুক্ত করবো।

---

## ⏸️ 1. What is Populate Comments Inside Post?

যখন একটি ব্লগ পোষ্টে মন্তব্য থাকে, তখন প্রতিটি মন্তব্যের তথ্য **Post** মডেলের সাথে সম্পর্কিত থাকে। আমরা **populate()** মেথড ব্যবহার করে ব্লগ পোষ্টের সাথে মন্তব্যগুলোকে একত্রে নিয়ে আসতে পারি। এই সম্পর্কটি একদিকে ব্লগ পোষ্ট এবং অন্যদিকে মন্তব্য (comments) এর মধ্যে থাকতে পারে, যেখানে এক পোস্টে অনেক মন্তব্য থাকতে পারে।

---

## ⏸️ 2. Set up Mongoose Models

আমাদের দুইটি মডেল তৈরি করতে হবে:
1. **Post** - ব্লগ পোষ্টের জন্য
2. **Comment** - মন্তব্যের জন্য

### Post Model

প্রথমে **Post** মডেল তৈরি করা যাক, যেখানে ব্লগ পোষ্টের শিরোনাম, কনটেন্ট এবং সম্পর্কিত মন্তব্য (comments) থাকবে।

```js
const mongoose = require('mongoose');

const postSchema = new mongoose.Schema({
  title: {
    type: String,
    required: true
  },
  content: {
    type: String,
    required: true
  },
  createdAt: {
    type: Date,
    default: Date.now
  },
  comments: [{
    type: mongoose.Schema.Types.ObjectId,
    ref: 'Comment'
  }]
});

const Post = mongoose.model('Post', postSchema);
module.exports = Post;
```

এখানে:
- **comments** ফিল্ডটি একটি অ্যারে, যেখানে **Comment** মডেলের **ObjectId** রেফারেন্স থাকবে।

### Comment Model

এখন **Comment** মডেল তৈরি করা যাক, যেখানে মন্তব্যের কনটেন্ট এবং লেখক (author) থাকবে।

```js
const mongoose = require('mongoose');

const commentSchema = new mongoose.Schema({
  content: {
    type: String,
    required: true
  },
  author: {
    type: String,
    required: true
  },
  createdAt: {
    type: Date,
    default: Date.now
  }
});

const Comment = mongoose.model('Comment', commentSchema);
module.exports = Comment;
```

এখানে:
- **Comment** মডেলটি একটি মন্তব্যের কনটেন্ট এবং লেখক ধারণ করে।

---

## ⏸️ 3. Add Comments to a Post

এখন, আমাদের একটি API তৈরি করতে হবে যা ব্লগ পোষ্টে মন্তব্য যোগ করবে। ব্লগ পোষ্টে মন্তব্য সংযুক্ত করতে হবে এবং সেই মন্তব্যের **ObjectId** ব্লগ পোষ্টের **comments** অ্যারেতে রাখা হবে।

### Example: Add Comment to Post

```js
const express = require('express');
const mongoose = require('mongoose');
const Post = require('./models/Post');
const Comment = require('./models/Comment');
const app = express();
const port = 3000;

mongoose.connect('mongodb://localhost:27017/blogAPI', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Add Comment to a Post
app.post('/posts/:postId/comments', async (req, res) => {
  try {
    const { content, author } = req.body;
    const postId = req.params.postId;

    // Find the post to add the comment to
    const post = await Post.findById(postId);
    if (!post) {
      return res.status(404).json({ message: 'Post not found' });
    }

    // Create a new comment
    const newComment = new Comment({
      content,
      author
    });

    // Save the new comment
    await newComment.save();

    // Add the comment's ObjectId to the post's comments array
    post.comments.push(newComment._id);
    await post.save();

    res.status(201).json(newComment);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- **POST `/posts/:postId/comments`** রিকোয়েস্টে একটি নতুন মন্তব্য তৈরি করা হয় এবং ব্লগ পোষ্টের **comments** অ্যারেতে **ObjectId** যুক্ত করা হয়।

---

## ⏸️ 4. Populate Comments Inside Post

এখন, আমাদের একটি API তৈরি করতে হবে যা ব্লগ পোষ্টের সাথে সম্পর্কিত মন্তব্যগুলো পপুলেট করে দেখাবে।

### Example: Get Post with Populated Comments

```js
// Get post with populated comments
app.get('/posts/:postId', async (req, res) => {
  try {
    const post = await Post.findById(req.params.postId).populate('comments');
    if (!post) {
      return res.status(404).json({ message: 'Post not found' });
    }
    res.json(post);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **GET `/posts/:postId`** রিকোয়েস্টে ব্লগ পোষ্টের তথ্য এবং সাথে সম্পর্কিত মন্তব্যগুলো **populate()** মেথড ব্যবহার করে একত্রে দেখা যাবে।

---

## ⏸️ 5. Testing the Populate Comments API

এখন, আমাদের তৈরি API গুলি পরীক্ষা করার জন্য **Postman** অথবা **Insomnia** ব্যবহার করতে হবে।

1. **POST `/posts/:postId/comments`** রিকোয়েস্ট পাঠান একটি নতুন মন্তব্য তৈরি করতে:
   - **Request Body:**
     ```json
     {
       "content": "This is a comment on the post.",
       "author": "Author Name"
     }
     ```

2. **GET `/posts/:postId`** রিকোয়েস্ট পাঠান ব্লগ পোষ্ট সহ সম্পর্কিত মন্তব্যগুলি পেতে:
   - **Response:**
     ```json
     {
       "title": "My Blog Post",
       "content": "Content for the blog post.",
       "comments": [
         {
           "_id": "commentObjectIdHere",
           "content": "This is a comment on the post.",
           "author": "Author Name",
           "createdAt": "2025-04-10T12:00:00Z"
         }
       ]
     }
     ```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Populate()** মেথড ব্যবহার করে একটি ব্লগ পোষ্টের মধ্যে সম্পর্কিত মন্তব্যগুলি পপুলেট করতে।
- কিভাবে **One-to-Many** সম্পর্ক তৈরি করে একটি পোস্টে মন্তব্য যুক্ত করতে হয়।
- ব্লগ পোষ্টের সাথে সম্পর্কিত মন্তব্যগুলি একত্রে প্রাপ্ত করতে API তৈরি করা।

আজকের দিনে আপনি শিখলেন কিভাবে **populate()** মেথড ব্যবহার করে MongoDB তে ব্লগ পোষ্টের মন্তব্যগুলি পপুলেট করবেন। 🎉🚀





# Day 52

✅ **আজকের দিনটি: Start MongoDB Transaction**

আজকের দিনে আমরা শিখবো কিভাবে **MongoDB** তে **transactions** ব্যবহার করা যায়। **MongoDB transactions** একাধিক ডাটাবেজ অপারেশনকে একত্রে কার্যকর করতে সক্ষম হয়, যা একক ইউনিট হিসেবে কাজ করে। অর্থাৎ, যদি কোনও একটি অপারেশন ব্যর্থ হয়, তাহলে পুরো ট্রানজেকশনটি রোলব্যাক করা হয়, ফলে ডাটাবেজে অর্ধেক আপডেটের পরিবর্তে সম্পূর্ণ রোলব্যাক হবে।

---

## ⏸️ 1. What is MongoDB Transaction?

MongoDB তে **transaction** একটি বা একাধিক ডাটাবেজ অপারেশন (যেমন, insert, update, delete) একত্রে পরিচালনা করার প্রক্রিয়া। যদি কোনও অপারেশন ব্যর্থ হয়, তাহলে পুরো ট্রানজেকশন রোলব্যাক করা হয়, যেন ডাটাবেজের অবস্থান অপরিবর্তিত থাকে।

MongoDB তে transaction ব্যবহার করতে, **session** এবং **transaction** পরিচালনা করতে হয়। এটি **ACID** (Atomicity, Consistency, Isolation, Durability) নিশ্চিত করে।

---

## ⏸️ 2. Setup MongoDB Connection with Transactions

MongoDB তে transaction পরিচালনা করার জন্য প্রথমে **MongoDB Atlas** অথবা লোকাল MongoDB ডাটাবেজে সংযোগ করতে হবে। এখানে আমরা **Mongoose** ব্যবহার করে MongoDB তে সংযোগ এবং ট্রানজেকশন শুরু করবো।

### MongoDB Connection Setup

```js
const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/yourDatabase', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => console.log('MongoDB connected'))
  .catch((err) => console.log(err));
```

এখানে, আমরা ডাটাবেজে সংযোগ স্থাপন করেছি। সংযোগ সফল হলে **MongoDB connected** ম্যাসেজ দেখানো হবে।

---

## ⏸️ 3. Create Models for Transactions

আজকের উদাহরণে আমরা দুটি মডেল ব্যবহার করবো: **User** এবং **Order**। একটি **User** মডেল থাকবে এবং একটি **Order** মডেল থাকবে যেখানে ব্যবহারকারী একটি পণ্য অর্ডার করবে। আমরা দেখবো কিভাবে একযোগে **User** এবং **Order** মডেলের অপারেশন পরিচালনা করা যায় MongoDB transaction এর মাধ্যমে।

### User Model

```js
const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
  name: String,
  balance: {
    type: Number,
    default: 0,
  },
});

const User = mongoose.model('User', userSchema);
module.exports = User;
```

### Order Model

```js
const mongoose = require('mongoose');

const orderSchema = new mongoose.Schema({
  product: String,
  price: Number,
  userId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'User',
  },
});

const Order = mongoose.model('Order', orderSchema);
module.exports = Order;
```

এখানে:
- **User** মডেলটি ব্যবহারকারীর নাম এবং ব্যালেন্স ধারণ করে।
- **Order** মডেলটি পণ্য এবং তার মূল্যসহ ব্যবহারকারীর সাথে সম্পর্কিত থাকে।

---

## ⏸️ 4. Start MongoDB Transaction

এখন আমরা **MongoDB Transaction** শুরু করবো। একাধিক অপারেশন একসাথে ট্রানজেকশনের মধ্যে করা হবে: 
1. একটি ব্যবহারকারীর ব্যালেন্স থেকে টাকা কমানো।
2. একটি অর্ডার তৈরি করা।

### Example: MongoDB Transaction for User Order

```js
const express = require('express');
const mongoose = require('mongoose');
const User = require('./models/User');
const Order = require('./models/Order');
const app = express();
const port = 3000;

app.use(express.json());

app.post('/order', async (req, res) => {
  const session = await mongoose.startSession();
  session.startTransaction();
  
  try {
    const { userId, product, price } = req.body;

    // Find user and check balance
    const user = await User.findById(userId).session(session);
    if (!user) {
      throw new Error('User not found');
    }
    if (user.balance < price) {
      throw new Error('Insufficient balance');
    }

    // Deduct balance from the user
    user.balance -= price;
    await user.save();

    // Create order
    const newOrder = new Order({
      product,
      price,
      userId: user._id,
    });
    await newOrder.save();

    // Commit transaction
    await session.commitTransaction();
    res.status(201).json({ message: 'Order placed successfully', order: newOrder });
  } catch (error) {
    // If any error occurs, rollback transaction
    await session.abortTransaction();
    res.status(500).json({ error: error.message });
  } finally {
    session.endSession();
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

### Explanation:

1. **Start Session:** প্রথমে `startSession()` মেথড ব্যবহার করে একটি সেশন শুরু হয়। এরপর সেশনটিকে ট্রানজেকশন শুরু করতে `startTransaction()` মেথড ব্যবহার করা হয়।
   
2. **Perform Operations:** 
   - প্রথমে ব্যবহারকারীর ব্যালেন্স চেক করা হয়। যদি ব্যালেন্স কম থাকে, তাহলে **Insufficient balance** এরর দেখানো হয়।
   - ব্যালেন্স থেকে মূল্য কমানো হয় এবং তারপর একটি নতুন অর্ডার তৈরি করা হয়।
   
3. **Commit or Abort Transaction:**
   - যদি সব কিছু ঠিক থাকে, তাহলে `commitTransaction()` মেথড ব্যবহার করে ট্রানজেকশন কমিট করা হয়।
   - যদি কোনো ভুল ঘটে, তাহলে `abortTransaction()` মেথড ব্যবহার করে ট্রানজেকশন রোলব্যাক করা হয়।

4. **End Session:** ট্রানজেকশন শেষে সেশনটি শেষ করা হয়।

---

## ⏸️ 5. Testing the MongoDB Transaction

এখন, আমরা এই API টির কার্যকারিতা পরীক্ষা করতে **Postman** অথবা **Insomnia** ব্যবহার করতে পারি।

### Example Request:

**POST `/order`**

Request Body:
```json
{
  "userId": "userObjectIdHere",
  "product": "Laptop",
  "price": 500
}
```

Response:
```json
{
  "message": "Order placed successfully",
  "order": {
    "_id": "orderObjectIdHere",
    "product": "Laptop",
    "price": 500,
    "userId": "userObjectIdHere"
  }
}
```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- কিভাবে **MongoDB Transaction** ব্যবহার করে একাধিক ডাটাবেজ অপারেশন একত্রে করা যায়।
- কিভাবে **session** এবং **transaction** ব্যবহারের মাধ্যমে ACID কমপ্লায়েন্স নিশ্চিত করা হয়।
- **commitTransaction()** এবং **abortTransaction()** এর মাধ্যমে ডাটাবেজে রোলব্যাক এবং সফলতা পরিচালনা করা হয়।

আজকের দিনে আপনি শিখলেন কিভাবে MongoDB তে **transactions** ব্যবহারের মাধ্যমে ডাটাবেজের বিভিন্ন অপারেশন একযোগে পরিচালনা করা যায়। 🎉🚀






# Day 53

✅ **আজকের দিনটি: Implement rollback using `abortTransaction()`**

আজকের দিনে আমরা শিখবো কিভাবে MongoDB তে ট্রানজেকশন ব্যবহারের সময় **rollback** করা যায় `abortTransaction()` ব্যবহার করে। MongoDB তে ট্রানজেকশন এর মাধ্যমে আমরা একাধিক অপারেশন একসাথে পরিচালনা করতে পারি, এবং যদি কোনও একটি অপারেশন ব্যর্থ হয়, তবে পুরো ট্রানজেকশনটি রোলব্যাক করা হয়। 

`abortTransaction()` মেথড MongoDB তে ব্যবহার হয় ট্রানজেকশনটি রোলব্যাক করার জন্য, যাতে ডাটাবেজে কোনও অপ্রত্যাশিত পরিবর্তন না ঘটে।

---

## ⏸️ 1. What is Rollback in MongoDB?

MongoDB তে **rollback** হল একটি অপারেশন যা ডাটাবেজের আগের অবস্থা ফিরে নিয়ে আসে। এটি তখন প্রয়োজন হয় যখন কোন একাধিক ডাটাবেজ অপারেশন একযোগে সম্পাদন করা হচ্ছে এবং যদি কোন একটি অপারেশন ব্যর্থ হয়, তাহলে পুরো ট্রানজেকশনটি রোলব্যাক করা হয়। এর মাধ্যমে ডাটাবেজে অযাচিত পরিবর্তন থেকে রক্ষা পাওয়া যায়।

---

## ⏸️ 2. Setup MongoDB Connection with Mongoose

এখানে আমরা MongoDB এর সাথে সংযোগ স্থাপন করবো এবং `startSession()` এর মাধ্যমে ট্রানজেকশন শুরু করবো।

### MongoDB Connection Setup

```js
const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/yourDatabase', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => console.log('MongoDB connected'))
  .catch((err) => console.log(err));
```

এখানে, আমরা MongoDB ডাটাবেজে সংযোগ স্থাপন করছি।

---

## ⏸️ 3. Create Models for Transaction Example

আমরা দুটি মডেল তৈরি করবো: **User** এবং **Order**। এখানে **User** মডেলটি একটি ব্যবহারকারীর তথ্য ধারণ করবে এবং **Order** মডেলটি ব্যবহারকারীর অর্ডার সংরক্ষণ করবে।

### User Model

```js
const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
  name: String,
  balance: {
    type: Number,
    default: 0,
  },
});

const User = mongoose.model('User', userSchema);
module.exports = User;
```

### Order Model

```js
const mongoose = require('mongoose');

const orderSchema = new mongoose.Schema({
  product: String,
  price: Number,
  userId: {
    type: mongoose.Schema.Types.ObjectId,
    ref: 'User',
  },
});

const Order = mongoose.model('Order', orderSchema);
module.exports = Order;
```

এখানে:
- **User** মডেল ব্যবহারকারী তথ্য ধারণ করে, যেমন ব্যালেন্স।
- **Order** মডেল অর্ডার সম্পর্কিত তথ্য ধারণ করে, যেমন পণ্যের নাম এবং মূল্য।

---

## ⏸️ 4. Implementing `abortTransaction()` for Rollback

এখন আমরা MongoDB তে **rollback** প্রয়োগ করবো। যদি কোন একটি অপারেশন ব্যর্থ হয়, তাহলে `abortTransaction()` ব্যবহার করে ট্রানজেকশন রোলব্যাক করা হবে।

### Example: Rollback with `abortTransaction()`

```js
const express = require('express');
const mongoose = require('mongoose');
const User = require('./models/User');
const Order = require('./models/Order');
const app = express();
const port = 3000;

app.use(express.json());

app.post('/order', async (req, res) => {
  const session = await mongoose.startSession();
  session.startTransaction();
  
  try {
    const { userId, product, price } = req.body;

    // Find user and check balance
    const user = await User.findById(userId).session(session);
    if (!user) {
      throw new Error('User not found');
    }
    if (user.balance < price) {
      throw new Error('Insufficient balance');
    }

    // Deduct balance from the user
    user.balance -= price;
    await user.save();

    // Create order
    const newOrder = new Order({
      product,
      price,
      userId: user._id,
    });
    await newOrder.save();

    // Commit transaction
    await session.commitTransaction();
    res.status(201).json({ message: 'Order placed successfully', order: newOrder });
  } catch (error) {
    // If any error occurs, rollback transaction
    await session.abortTransaction();
    res.status(500).json({ error: error.message });
  } finally {
    session.endSession();
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

### Explanation:

1. **Start Session and Transaction:** 
   - প্রথমে, আমরা `startSession()` মেথড ব্যবহার করে একটি সেশন শুরু করি এবং পরে `startTransaction()` মেথড ব্যবহার করে একটি ট্রানজেকশন শুরু করি।

2. **Perform Operations:** 
   - **User Balance Check:** প্রথমে ব্যবহারকারীর ব্যালেন্স চেক করা হয়। যদি ব্যালেন্স কম হয়, তাহলে **Insufficient balance** এরর দেখানো হয়।
   - **Deduct User Balance:** ব্যালেন্স থেকে নির্দিষ্ট পরিমাণ টাকা কমানো হয়।
   - **Create Order:** তারপর একটি নতুন অর্ডার তৈরি করা হয়।

3. **Commit or Abort Transaction:** 
   - যদি সমস্ত অপারেশন সঠিকভাবে সম্পন্ন হয়, তাহলে `commitTransaction()` ব্যবহার করে ট্রানজেকশনটি সফলভাবে সম্পন্ন করা হয়।
   - যদি কোন একটি অপারেশন ব্যর্থ হয়, তাহলে `abortTransaction()` ব্যবহার করে ট্রানজেকশনটি রোলব্যাক করা হয়, অর্থাৎ পূর্বের অবস্থা ফিরে আসে।

4. **End Session:** 
   - সেশন শেষে, `endSession()` মেথড ব্যবহার করে সেশনটি শেষ করা হয়।

---

## ⏸️ 5. Testing the Rollback

এখন, আমরা এই API টির কার্যকারিতা পরীক্ষা করতে **Postman** বা **Insomnia** ব্যবহার করতে পারি।

### Example Request:

**POST `/order`**

Request Body:
```json
{
  "userId": "userObjectIdHere",
  "product": "Laptop",
  "price": 500
}
```

Response:
```json
{
  "message": "Order placed successfully",
  "order": {
    "_id": "orderObjectIdHere",
    "product": "Laptop",
    "price": 500,
    "userId": "userObjectIdHere"
  }
}
```

এছাড়া, যদি কোন ব্যালেন্সের সমস্যা হয়, তখন:
```json
{
  "error": "Insufficient balance"
}
```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- কিভাবে MongoDB তে **rollback** প্রয়োগ করা হয় `abortTransaction()` ব্যবহার করে।
- কিভাবে একাধিক অপারেশন একযোগে পরিচালনা করা যায় MongoDB তে ট্রানজেকশন ব্যবহার করে।
- কিভাবে **transaction commit** এবং **rollback** পরিচালনা করা হয় সফল এবং ব্যর্থ অপারেশনের ক্ষেত্রে।

এটি MongoDB এর ট্রানজেকশন ব্যবহারের সময় রোলব্যাক প্রয়োগ করার একটি গুরুত্বপূর্ণ অংশ ছিল। 🎉🚀





# Day 54

✅ **আজকের দিনটি: Soft delete using flags**

আজকের দিনে আমরা শিখবো কিভাবে **Soft Delete** পরিচালনা করা যায় MongoDB তে। সাধারণত **soft delete** এমন একটি প্রক্রিয়া, যেখানে ডাটা ডিলিট করা হয় না, বরং ডাটার একটি ফ্ল্যাগ সেট করা হয়, যা সেই রেকর্ডটি ডিলিট হয়েছে বলে চিহ্নিত করে। এর মাধ্যমে, ডাটা সহজে পুনরুদ্ধার করা যায় এবং ইতিহাস সংরক্ষণ করা সম্ভব হয়।

---

## ⏸️ 1. What is Soft Delete?

**Soft Delete** হল এমন একটি পদ্ধতি যেখানে কোনো ডাটা ডিলিট না করে, তার স্থানে একটি ফ্ল্যাগ সেট করা হয়, যা সেই ডাটাকে "ডিলিট" বা "অক্রিয়" হিসেবে চিহ্নিত করে। এর মাধ্যমে ডাটা এখনও ডাটাবেজে রয়ে যায় এবং পরে প্রয়োজন হলে পুনরুদ্ধার করা যেতে পারে।

MongoDB তে soft delete প্রক্রিয়া খুবই জনপ্রিয় কারণ এটি ডাটা হারানোর ঝুঁকি কমায় এবং অস্থায়ীভাবে ডাটা সংরক্ষণ করা সহজ করে।

---

## ⏸️ 2. Why Soft Delete?

- **Data Retention:** ডাটা যদি কখনও পুনরুদ্ধার করতে হয়, তবে এটি সহজ হবে কারণ এটি ডাটাবেজে অবিকৃতভাবে সংরক্ষিত থাকবে।
- **Audit Trail:** আপনি কি কখনও জানতে চান কিভাবে এবং কখন ডাটা ডিলিট হয়েছিল? Soft delete এর মাধ্যমে আপনি তা ট্র্যাক করতে পারবেন।
- **Unwanted Deletion Prevention:** যদি কোনো ভুলবশত ডাটা ডিলিট হয়ে যায়, তবে soft delete ব্যবহারের মাধ্যমে তা পুনরুদ্ধার করা সম্ভব হবে।

---

## ⏸️ 3. Create Schema with Soft Delete Flag

MongoDB তে soft delete করার জন্য আমরা আমাদের মডেল স্কিমাতে একটি **flag** ফিল্ড যোগ করবো যা রেকর্ডটির ডিলিট স্টেটাস ট্র্যাক করবে।

### Example: User Model with Soft Delete

```js
const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
  },
  email: {
    type: String,
    required: true,
    unique: true,
  },
  deleted: {
    type: Boolean,
    default: false, // flag to indicate if user is deleted or not
  },
  createdAt: {
    type: Date,
    default: Date.now,
  },
});

const User = mongoose.model('User', userSchema);
module.exports = User;
```

### Explanation:

- **deleted:** এটি একটি **Boolean** ফ্ল্যাগ যা রেকর্ডটির ডিলিট হওয়া না হওয়া চিহ্নিত করে। যদি এটি `true` হয়, তাহলে রেকর্ডটি ডিলিটেড হিসেবে চিহ্নিত হবে।
- **default:** ডিফল্টভাবে `false` থাকবে, অর্থাৎ রেকর্ডটি ডিলিট হওয়া হয়নি।

---

## ⏸️ 4. Implement Soft Delete in Routes

এখন আমরা **soft delete** এর জন্য একটি API তৈরি করবো। এই API ব্যবহারকারীকে ডিলিট করতে পারবে, তবে ডিলিটের পরিবর্তে **deleted** ফ্ল্যাগটি `true` সেট করবে।

### Soft Delete API Endpoint

```js
const express = require('express');
const mongoose = require('mongoose');
const User = require('./models/User');
const app = express();
const port = 3000;

app.use(express.json());

// Soft delete user by setting 'deleted' flag to true
app.delete('/user/:id', async (req, res) => {
  try {
    const { id } = req.params;

    // Find user by ID
    const user = await User.findById(id);
    if (!user) {
      return res.status(404).json({ message: 'User not found' });
    }

    // Mark as deleted
    user.deleted = true;
    await user.save();

    res.status(200).json({ message: 'User soft deleted successfully', user });
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

### Explanation:

- **Find User by ID:** আমরা প্রথমে ব্যবহারকারীকে তার **ID** দিয়ে খুঁজে বের করি।
- **Set Deleted Flag:** তারপর `deleted = true` করে সেই ব্যবহারকারীকে "ডিলিট" হিসেবে চিহ্নিত করি।
- **Save User:** শেষমেশ আমরা ব্যবহারকারীকে সেভ করি, যাতে ডাটাবেজে এই পরিবর্তনটি সংরক্ষিত হয়।

---

## ⏸️ 5. Implement Soft Delete in Queries

Soft delete করার পর, আপনি সাধারণত ডাটাবেজ থেকে **ডিলিটেড রেকর্ড**গুলি দেখতে চান না। তাই আমাদের **find** এবং অন্যান্য queries এ `deleted: false` ফিল্টার ব্যবহার করা উচিত।

### Find All Non-deleted Users

```js
app.get('/users', async (req, res) => {
  try {
    const users = await User.find({ deleted: false });
    res.status(200).json(users);
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});
```

### Explanation:

- **deleted: false:** এই ফিল্টার ব্যবহার করে আমরা শুধুমাত্র **ডিলিটেড না হওয়া** ব্যবহারকারীদের দেখতে পাচ্ছি।

---

## ⏸️ 6. Restoring Soft Deleted Data

ধরা যাক, যদি আপনি কোন ডিলিটেড রেকর্ড পুনরুদ্ধার করতে চান, তাহলে আপনি ফ্ল্যাগটি আবার `false` করে দিতে পারেন।

### Restore Soft Deleted User

```js
app.put('/user/restore/:id', async (req, res) => {
  try {
    const { id } = req.params;

    // Find soft deleted user by ID
    const user = await User.findById(id);
    if (!user || !user.deleted) {
      return res.status(404).json({ message: 'User not found or not deleted' });
    }

    // Restore user by setting 'deleted' flag to false
    user.deleted = false;
    await user.save();

    res.status(200).json({ message: 'User restored successfully', user });
  } catch (error) {
    res.status(500).json({ message: error.message });
  }
});
```

### Explanation:

- **Find and Check Deleted Flag:** প্রথমে আমরা ব্যবহারকারী খুঁজে বের করি এবং যাচাই করি যে ব্যবহারকারী **ডিলিটেড** কি না।
- **Restore:** যদি ব্যবহারকারী ডিলিটেড থাকে, তবে আমরা `deleted` ফ্ল্যাগটি `false` করে তাকে পুনরুদ্ধার করি।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Soft delete** কিভাবে MongoDB তে ফ্ল্যাগ ব্যবহার করে করা যায়।
- **Soft delete** করার মাধ্যমে ডাটা **অস্থায়ীভাবে ডিলিট** করা এবং **পুনরুদ্ধার** করা।
- কিভাবে **queries** এ soft deleted ডাটা ফিল্টার করা যায়।
- কিভাবে **restore** করা যায় soft deleted ডাটা।

এটি MongoDB তে **soft delete** এর একটি গুরুত্বপূর্ণ অংশ ছিল। 🎉🚀






# Day 55

✅ **আজকের দিনটি: Wrap DB operations in transaction**

আজকের দিনে আমরা শিখবো কিভাবে **MongoDB তে transaction** ব্যবহার করে একাধিক ডাটাবেস অপারেশন একসাথে সম্পন্ন করা যায়। MongoDB 4.0 সংস্করণ থেকে **transactions** সমর্থিত, যা ACID (Atomicity, Consistency, Isolation, Durability) গুণাবলী প্রদান করে।

---

## ⏸️ 1. What is a Database Transaction?

**Database Transaction** এমন একটি অপারেশন যা একাধিক ডাটাবেস কর্মপদ্ধতি (operations) একত্রে সম্পাদন করে, এবং সমস্ত কর্মপদ্ধতি একসাথে সফল বা ব্যর্থ হতে হবে। এর মানে হল যে যদি একটি অপারেশন ব্যর্থ হয়, তাহলে পুরো transaction ব্যর্থ হয়ে যাবে এবং সমস্ত পরিবর্তন উল্টে যাবে (rollback)।

একটি transaction তিনটি গুরুত্বপূর্ণ গুণাবলী ধারণ করে:
1. **Atomicity:** সমস্ত অপারেশন একত্রে সফল বা ব্যর্থ হবে।
2. **Consistency:** ডাটাবেসের অবস্থান পূর্বের সাথে সঙ্গতিপূর্ণ থাকবে।
3. **Isolation:** একটি ট্রানজেকশনের অপারেশন অন্য ট্রানজেকশনের সাথে হস্তক্ষেপ করবে না।
4. **Durability:** সফল ট্রানজেকশন শেষ হলে, তার ফলাফল চিরকাল স্থায়ী হবে।

---

## ⏸️ 2. Why Use Transactions?

MongoDB তে transactions ব্যবহারের মাধ্যমে:
- **Consistency** নিশ্চিত করা যায়, যেখানে একাধিক ডাটাবেস অপারেশন একত্রে সম্পাদিত হতে হয়।
- **Data integrity** বজায় রাখা যায়, বিশেষ করে যখন একাধিক ডাটাবেস টেবিল বা কোলেকশন একই সময়ে আপডেট করতে হয়।

---

## ⏸️ 3. How to Use Transactions in MongoDB?

MongoDB তে ট্রানজেকশন ব্যবহার করার জন্য, আমরা **session** তৈরি করি এবং সেই session এর অধীনে সমস্ত অপারেশন সম্পাদন করি। যদি কোনো অপারেশন ব্যর্থ হয়, আমরা **rollback** করতে পারি।

---

## ⏸️ 4. Steps to Wrap DB Operations in a Transaction

এখন আমরা দেখবো কিভাবে **MongoDB তে transaction** পরিচালনা করতে হয়।

### Example: Transfer Money Between Two Accounts (Transactional Operation)

আমরা একটি উদাহরণ তৈরি করবো যেখানে একটি অ্যাকাউন্ট থেকে অন্য অ্যাকাউন্টে টাকা ট্রান্সফার করা হবে। এই কাজটি একাধিক ডাটাবেস অপারেশন সম্পন্ন করে, তাই আমরা এটি একটি ট্রানজেকশনে রাখতে চাই।

### 4.1. Transaction Setup & Handling

```js
const mongoose = require('mongoose');

// Define schemas for Account model
const accountSchema = new mongoose.Schema({
  name: String,
  balance: Number,
});

const Account = mongoose.model('Account', accountSchema);

const transferMoney = async (senderId, receiverId, amount) => {
  const session = await mongoose.startSession();
  session.startTransaction();

  try {
    const sender = await Account.findById(senderId).session(session);
    const receiver = await Account.findById(receiverId).session(session);

    if (!sender || !receiver) {
      throw new Error('Sender or Receiver not found');
    }

    // Check if sender has enough balance
    if (sender.balance < amount) {
      throw new Error('Insufficient balance');
    }

    // Deduct from sender and add to receiver
    sender.balance -= amount;
    receiver.balance += amount;

    // Save both documents
    await sender.save();
    await receiver.save();

    // Commit the transaction
    await session.commitTransaction();
    session.endSession();
    console.log('Transaction successful');
  } catch (error) {
    // Rollback the transaction in case of error
    await session.abortTransaction();
    session.endSession();
    console.error('Transaction failed', error);
  }
};
```

### Explanation:

1. **Start a session**: 
   - প্রথমে একটি session শুরু করা হয় `mongoose.startSession()` এর মাধ্যমে।
2. **Start Transaction**:
   - তারপর সেই session এ ট্রানজেকশন শুরু করা হয় `session.startTransaction()` দিয়ে।
3. **Perform DB Operations**:
   - `findById()` ব্যবহার করে sender এবং receiver অ্যাকাউন্ট খোঁজা হয় এবং সেই session এ কার্যক্রম করা হয়।
   - এর পরে sender অ্যাকাউন্ট থেকে টাকা কাটা হয় এবং receiver অ্যাকাউন্টে যোগ করা হয়।
4. **Commit Transaction**:
   - সবকিছু ঠিক থাকলে, `session.commitTransaction()` ব্যবহার করে ট্রানজেকশন কমিট করা হয়।
5. **Rollback Transaction**:
   - যদি কোনো error ঘটে, তাহলে `session.abortTransaction()` এর মাধ্যমে ট্রানজেকশন বাতিল করা হয় এবং কোন পরিবর্তন ডাটাবেসে সেভ হয় না।

---

## ⏸️ 5. Using Transactions with Multiple Collections

MongoDB তে একাধিক কোলেকশনের মধ্যে ট্রানজেকশন পরিচালনা করা সম্ভব। আপনি যদি একাধিক কোলেকশনে ডাটা আপডেট করতে চান, তবে সেগুলিও একটি সেশন ব্যবহার করে একত্রে সম্পন্ন করতে হবে।

```js
const orderSchema = new mongoose.Schema({
  productId: mongoose.Schema.Types.ObjectId,
  userId: mongoose.Schema.Types.ObjectId,
  quantity: Number,
  status: String,
});

const Order = mongoose.model('Order', orderSchema);

const createOrderAndDeductStock = async (userId, productId, quantity) => {
  const session = await mongoose.startSession();
  session.startTransaction();

  try {
    // Create order
    const order = new Order({ productId, userId, quantity, status: 'pending' });
    await order.save({ session });

    // Deduct stock from product (assuming we have a Product model)
    const product = await Product.findById(productId).session(session);
    if (!product || product.stock < quantity) {
      throw new Error('Insufficient stock');
    }

    product.stock -= quantity;
    await product.save({ session });

    // Commit transaction
    await session.commitTransaction();
    session.endSession();
    console.log('Order created and stock updated');
  } catch (error) {
    // Rollback in case of error
    await session.abortTransaction();
    session.endSession();
    console.error('Order creation failed', error);
  }
};
```

### Explanation:

- আমরা এখানে **Order** কোলেকশনের সাথে **Product** কোলেকশনকেও আপডেট করছি।
- transaction এর মাধ্যমে **order** এবং **stock** একযোগে আপডেট করা হচ্ছে।
- যদি কোনো একটি অপারেশন ব্যর্থ হয়, তখন **rollback** হবে এবং সমস্ত পরিবর্তন বাতিল হয়ে যাবে।

---

## 📌 Summary:

আজকের দিনে আপনি শিখলেন কিভাবে MongoDB তে **transaction** ব্যবহার করে একাধিক ডাটাবেস অপারেশন একসাথে সম্পাদন করতে হয়। এখানে আমরা দেখেছি কিভাবে:
- **Transaction** শুরু এবং শেষ করা হয়।
- একাধিক **collections** এর মধ্যে **atomic** (একক) অপারেশন পরিচালনা করা যায়।
- **Commit** এবং **Rollback** অপারেশন ব্যবহার করা হয়।

এটি খুবই গুরুত্বপূর্ণ একটি দক্ষতা যখন আপনি ডাটাবেসের সাথে কাজ করেন, বিশেষ করে যখন আপনি নিশ্চিত করতে চান যে সমস্ত অপারেশন একযোগে সফল বা ব্যর্থ হবে। 🚀




# Day 56

✅ **আজকের দিনটি: Mini project: E-commerce checkout logic with rollback**

আজকের দিনে আমরা একটি **E-commerce checkout logic** তৈরি করবো যেখানে **rollback** ব্যবহার করা হবে। এটি একটি মিনিপ্রজেক্ট যা **MongoDB transaction** ব্যবহার করে একটি **checkout process** বাস্তবায়ন করবে, যেখানে বিভিন্ন অপারেশন যেমন **order creation**, **inventory update**, এবং **payment processing** একযোগে সম্পন্ন করা হবে। যদি কোনো অপারেশন ব্যর্থ হয়, তখন **rollback** হবে এবং সমস্ত পরিবর্তন পূর্বাবস্থায় ফিরে যাবে।

---

## ⏸️ 1. Project Overview

আমরা একটি **E-commerce checkout system** তৈরি করবো যেখানে গ্রাহক একটি পণ্য কিনবে, পণ্যের পরিমাণ স্টক থেকে কমানো হবে এবং একটি **order** তৈরি হবে। যদি কোনো একটি ধাপে সমস্যা হয় (যেমন, **payment failure** বা **insufficient stock**), তাহলে সমস্ত পরিবর্তন **rollback** হয়ে যাবে এবং গ্রাহককে সঠিক তথ্য জানানো হবে।

---

## ⏸️ 2. Steps to Implement Checkout Logic

### Step 1: Define the Models
আমরা ৩টি মডেল ব্যবহার করবো:
1. **Product** - যেখানে পণ্যের তথ্য থাকবে (যেমন নাম, দাম, স্টক পরিমাণ)
2. **Order** - যেখানে গ্রাহকের অর্ডারের তথ্য থাকবে (যেমন পণ্যের তথ্য, পরিমাণ, স্ট্যাটাস)
3. **Payment** - যেখানে পেমেন্ট সম্পর্কিত তথ্য থাকবে (যেমন পেমেন্ট স্ট্যাটাস)

### Step 2: Start Transaction for Checkout
এখানে আমরা একাধিক ডাটাবেস অপারেশন একত্রে করবো:
- পণ্যের স্টক কমানো
- নতুন অর্ডার তৈরি করা
- পেমেন্ট প্রসেস করা

যদি কোনো অপারেশন ব্যর্থ হয়, তখন আমরা **rollback** করবো যাতে ডাটাবেসে কোনো অস্বাভাবিক পরিবর্তন না হয়।

### Step 3: Rollback in Case of Failure
যদি কোনো একটি অপারেশন ব্যর্থ হয় (যেমন পেমেন্টের সময় সমস্যা হয়), তখন আমরা ট্রানজেকশন **abort** করে সমস্ত পরিবর্তন **rollback** করবো।

---

## ⏸️ 3. Code Implementation

### 3.1. Define Product, Order, and Payment Models

```js
const mongoose = require('mongoose');

// Product Model
const productSchema = new mongoose.Schema({
  name: String,
  price: Number,
  stock: Number,
});

const Product = mongoose.model('Product', productSchema);

// Order Model
const orderSchema = new mongoose.Schema({
  productId: mongoose.Schema.Types.ObjectId,
  quantity: Number,
  totalAmount: Number,
  status: String,
});

const Order = mongoose.model('Order', orderSchema);

// Payment Model
const paymentSchema = new mongoose.Schema({
  orderId: mongoose.Schema.Types.ObjectId,
  paymentStatus: String,
  paymentAmount: Number,
});

const Payment = mongoose.model('Payment', paymentSchema);
```

### 3.2. Checkout Logic with Transaction

```js
const checkout = async (userId, productId, quantity) => {
  const session = await mongoose.startSession();
  session.startTransaction();

  try {
    // Step 1: Check Product Availability
    const product = await Product.findById(productId).session(session);
    if (!product || product.stock < quantity) {
      throw new Error('Insufficient stock');
    }

    // Step 2: Create Order
    const totalAmount = product.price * quantity;
    const order = new Order({
      productId,
      quantity,
      totalAmount,
      status: 'pending',
    });
    await order.save({ session });

    // Step 3: Process Payment (Simulated)
    const paymentStatus = 'success'; // Simulate payment status
    if (paymentStatus !== 'success') {
      throw new Error('Payment failed');
    }

    // Step 4: Create Payment Record
    const payment = new Payment({
      orderId: order._id,
      paymentStatus,
      paymentAmount: totalAmount,
    });
    await payment.save({ session });

    // Step 5: Update Product Stock
    product.stock -= quantity;
    await product.save({ session });

    // Commit Transaction
    await session.commitTransaction();
    session.endSession();
    console.log('Checkout completed successfully');
  } catch (error) {
    // Rollback Transaction in case of failure
    await session.abortTransaction();
    session.endSession();
    console.error('Checkout failed:', error);
  }
};
```

### Explanation of Code:

1. **Session Start**: আমরা প্রথমে একটি session শুরু করি `mongoose.startSession()` দিয়ে, যাতে transaction পরিচালনা করতে পারি।
2. **Product Availability Check**: পণ্যের স্টক যাচাই করা হয়, যদি পর্যাপ্ত স্টক না থাকে, তাহলে error throw করা হয় এবং transaction abort হয়ে যাবে।
3. **Order Creation**: গ্রাহকের জন্য একটি নতুন অর্ডার তৈরি করা হয় এবং সেটি **Order** কোলেকশনে সংরক্ষণ করা হয়।
4. **Payment Processing**: পেমেন্ট প্রসেস করা হয়, এবং যদি পেমেন্ট ব্যর্থ হয় (যেমন simulated payment failure), তখন transaction abort হয়ে যাবে।
5. **Product Stock Update**: পণ্যের স্টক কমানো হয়, এটি শুধু তখনই হবে যদি সবকিছু সফলভাবে সম্পন্ন হয়।
6. **Commit or Rollback**: যদি সমস্ত অপারেশন সফল হয়, আমরা **commitTransaction()** ব্যবহার করে ট্রানজেকশন কমিট করি। যদি কোনো সমস্যা হয়, আমরা **abortTransaction()** ব্যবহার করে ট্রানজেকশনটি বাতিল করি এবং সমস্ত পরিবর্তন উল্টে যাবে।

---

## ⏸️ 4. Testing the Checkout Logic

আপনার কোড সফলভাবে কাজ করার জন্য, আপনি বিভিন্ন পরিস্থিতি পরীক্ষা করতে পারেন:
1. **Insufficient stock**: পণ্যের স্টক কম থাকলে অর্ডার হবে না এবং rollback হবে।
2. **Payment failure**: যদি পেমেন্ট ব্যর্থ হয়, তাহলে সমস্ত ডাটাবেস পরিবর্তন rollback হবে।
3. **Successful checkout**: সবকিছু ঠিকঠাক থাকলে, অর্ডার তৈরি হবে, স্টক আপডেট হবে এবং পেমেন্ট সংরক্ষণ হবে।

---

## 📌 Summary:

আজকের দিনে আপনি শিখলেন কিভাবে **E-commerce checkout logic** তৈরি করতে হয় MongoDB **transaction** ব্যবহার করে। এখানে আমরা দেখেছি:
- একাধিক অপারেশন যেমন **order creation**, **inventory update**, এবং **payment processing** একযোগে সম্পন্ন করতে।
- **Rollback** কিভাবে কাজ করে যখন কোনো অপারেশন ব্যর্থ হয়।
- কিভাবে ট্রানজেকশনের মাধ্যমে ডাটাবেসের integrity রক্ষা করা যায়।

এটি একটি গুরুত্বপূর্ণ দক্ষতা, বিশেষ করে যখন আপনি বড় E-commerce সিস্টেম তৈরি করেন, যেখানে বিভিন্ন ডাটাবেস অপারেশন একযোগে পরিচালনা করতে হয়। 🚀



# Day 56

✅ **আজকের দিনটি: Caching**

আজকের দিনে আমরা **Caching** নিয়ে কাজ করবো। Caching হল একটি গুরুত্বপূর্ণ কৌশল যা ডাটাবেস, অ্যাপ্লিকেশন, এবং API পারফরম্যান্স উন্নত করতে সাহায্য করে। এতে করা হয় নির্দিষ্ট ডেটা পুনরায় বারবার ডাটাবেস বা অন্য উৎস থেকে রিট্রিভ করার পরিবর্তে তা এক জায়গায় সঞ্চয় করা, যাতে পরবর্তীতে দ্রুত অ্যাক্সেস করা যায়।

Caching ব্যবহারের মাধ্যমে, আমরা বারবার একই ডেটা পুনরুদ্ধারের সময়ের জন্য ব্যয় কমাতে পারি এবং অ্যাপ্লিকেশনের পারফরম্যান্স অনেক দ্রুত করতে পারি।

---

## ⏸️ 1. What is Caching?

**Caching** হল একটি পদ্ধতি যেখানে কম্পিউটিং রিসোর্স (যেমন ডেটাবেস) থেকে ডেটা বারবার বের করার পরিবর্তে তা কিছু সময়ের জন্য **temporary storage** বা **cache**-এ রাখার মাধ্যমে পারফরম্যান্স উন্নত করা হয়। 

Caching সাধারণত ব্যবহার করা হয়:
- API বা ডাটাবেস থেকে ডেটা প্রাপ্তির সময় খরচ কমানোর জন্য।
- ব্যবহারকারীর জন্য দ্রুততর অভিজ্ঞতা তৈরির জন্য।

---

## ⏸️ 2. Types of Caching

### 2.1. **In-memory Caching**
- এটি একধরনের **volatile memory** caching, যেখানে ডেটা RAM-এ সঞ্চিত হয়।
- এটি অনেক দ্রুত, তবে **server restart** হলে ডেটা হারিয়ে যায়।

### 2.2. **Persistent Caching**
- এখানে ডেটা স্টোরেজ ডিভাইস বা ডাটাবেসে সঞ্চিত থাকে।
- এই ধরনের ক্যাশিং দীর্ঘস্থায়ী, এবং ডেটা **server restart** হওয়ার পরও অটোমেটিক্যালি রিস্টোর হয়।

---

## ⏸️ 3. Popular Caching Strategies

### 3.1. **Cache Aside**
- অ্যাপ্লিকেশন প্রথমে ডেটা ক্যাশে রেখে, তারপর সেটি ডাটাবেস থেকে রিট্রিভ করে।
- একবার ডেটা ক্যাশে চলে আসলে, পরবর্তী রিকোয়েস্ট সরাসরি ক্যাশ থেকে আসে।
- **Pros**: অধিক কন্ট্রোল, প্রয়োজন অনুযায়ী ক্যাশ করা যায়।
- **Cons**: ক্যাশে ডেটা সঠিক থাকতে হবে, এবং cache miss হলে ডাটাবেস থেকে ডেটা নিয়ে আসা সময়সাপেক্ষ হতে পারে।

### 3.2. **Read-through Cache**
- অ্যাপ্লিকেশন যখন ডেটা রিকোয়েস্ট করে, ক্যাশ প্রথমে চেক করে, যদি ডেটা না থাকে, তাহলে ডাটাবেস থেকে এনে ক্যাশে রাখে।
- **Pros**: ক্যাশ আপডেট করার ঝামেলা কম।
- **Cons**: অ্যাপ্লিকেশন কনফিগার করা কঠিন হতে পারে।

### 3.3. **Write-through Cache**
- যখন ডেটা ডাটাবেসে লেখা হয়, তখন সেটা ক্যাশেও লেখা হয়।
- **Pros**: ক্যাশ এবং ডাটাবেস দুটি একই ডেটা ধারণ করে।
- **Cons**: ডেটা আপডেটের সময় বেশি সময় লাগে।

---

## ⏸️ 4. Implementing Caching in Express.js

এখন আমরা **Express.js** অ্যাপ্লিকেশনে ক্যাশিং কিভাবে ব্যবহার করতে পারি, সেটি দেখব।

### 4.1. Use `redis` for Caching

আমরা এখানে **Redis** ব্যবহার করবো, যা একটি জনপ্রিয় **in-memory caching** সিস্টেম। Redis খুব দ্রুত কাজ করে এবং সাধারণত **key-value store** হিসেবে ব্যবহার করা হয়।

#### Install Redis:

```bash
npm install redis
```

#### Setting Up Redis Cache:

```js
const redis = require('redis');
const client = redis.createClient(); // Create Redis client

client.on('connect', () => {
  console.log('Connected to Redis');
});

// Set data in cache
client.set('user:123', JSON.stringify({ name: 'John', age: 30 }));

// Get data from cache
client.get('user:123', (err, data) => {
  if (err) throw err;
  console.log('Data from cache:', JSON.parse(data));
});
```

### 4.2. Cache API Response in Express

```js
const express = require('express');
const redis = require('redis');
const client = redis.createClient();
const app = express();

client.on('connect', () => {
  console.log('Connected to Redis');
});

app.get('/api/products', (req, res) => {
  const cacheKey = 'products';
  
  // Check if data is in cache
  client.get(cacheKey, (err, data) => {
    if (data) {
      console.log('Data from cache');
      return res.json(JSON.parse(data));
    }

    // Fetch data from DB if not in cache
    // Simulating fetching from database
    const products = [
      { id: 1, name: 'Product A' },
      { id: 2, name: 'Product B' },
    ];

    // Set data in cache with an expiry time of 1 hour
    client.setex(cacheKey, 3600, JSON.stringify(products));

    console.log('Data from database');
    return res.json(products);
  });
});

app.listen(3000, () => {
  console.log('Server running on port 3000');
});
```

### Explanation:
1. **Redis Client**: আমরা Redis client সেট আপ করেছি এবং Express.js অ্যাপ্লিকেশনে ব্যবহার করেছি।
2. **Check Cache**: API রিকোয়েস্টের আগেই আমরা Redis cache চেক করি। যদি ডেটা থাকে, তখন তা সরাসরি রিটার্ন করি।
3. **Database Fallback**: যদি cache না থাকে, তখন আমরা ডাটাবেস থেকে ডেটা ফেচ করি এবং তা Redis cache-এ সংরক্ষণ করি।

---

## ⏸️ 5. Cache Expiry

Redis ক্যাশে থাকা ডেটার জন্য আপনি **expiry time** সেট করতে পারেন, যা ক্যাশে থাকা ডেটা নির্দিষ্ট সময় পর মুছে ফেলবে।

```js
client.setex('user:123', 3600, JSON.stringify({ name: 'John', age: 30 }));
```
এখানে, `3600` সেকেন্ডের মধ্যে ক্যাশের ডেটা মুছে যাবে।

---

## ⏸️ 6. Cache Invalidation

ক্যাশ ইনভ্যালিডেশন বা ক্যাশের ডেটা খালি করা অনেক সময় গুরুত্বপূর্ণ হয়ে পড়ে যখন ডেটা পরিবর্তন হয়। Redis-এ ক্যাশ মুছে ফেলার জন্য ব্যবহার করতে পারেন:

```js
client.del('user:123'); // Remove data from cache
```

---

## 📌 Summary:

আজকের দিনটি ছিল **Caching** নিয়ে কাজ করার দিন। Caching ব্যবহার করার মাধ্যমে আপনি আপনার অ্যাপ্লিকেশনের পারফরম্যান্স উন্নত করতে পারবেন। **Redis** হলো একটি জনপ্রিয় **in-memory caching** টুল যা আপনি Express.js অ্যাপ্লিকেশনে সহজেই ব্যবহার করতে পারেন।

Caching সিস্টেমের মধ্যে **cache miss** এবং **cache hit** বুঝে কাজ করা অত্যন্ত গুরুত্বপূর্ণ, এবং ক্যাশের ডেটা সঠিক ও সঙ্গতিপূর্ণ রাখতে **cache invalidation** সঠিকভাবে ব্যবহারের উপর গুরুত্ব দেওয়া উচিত।

এটি একটি গুরুত্বপূর্ণ দক্ষতা, বিশেষ করে যখন আপনি **high-performance** অ্যাপ্লিকেশন তৈরি করেন। 🚀





