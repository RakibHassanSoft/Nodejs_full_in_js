# 📘 Introduction to MongoDB and Mongoose

## 🟢 MongoDB

**MongoDB** is a **NoSQL, open-source, cross-platform, document-oriented database system**. 
It is designed to store, query, and process large volumes of semi-structured data using a flexible and scalable architecture.

### 🧱 Core Concepts
- MongoDB stores data as **documents**, which are key-value pairs in a format similar to JSON (called **BSON** - Binary JSON).
- A **document** is the basic unit of data in MongoDB, and documents are grouped into **collections**.
- Collections are analogous to tables in relational databases, while documents are like rows.

### ✨ Key Features:
- **Document-based:** Stores data in flexible, JSON-like documents, making it easy to evolve schemas over time.
- **Schema-less:** Each document in a collection can have a different structure. Great for agile and rapid development.
- **Scalable:** MongoDB supports **horizontal scaling** through **sharding**, allowing it to handle huge amounts of data.
- **High Performance:** Optimized for speed and capable of handling a large number of read/write operations.
- **Replication:** Built-in support for **replica sets** ensures high availability and automatic failover.
- **Indexing:** Supports various types of indexes for faster query performance (single field, compound, text, geospatial, etc.).
- **Aggregation Framework:** A powerful pipeline-based system for transforming and analyzing data.
- **ACID Transactions:** From version 4.0+, MongoDB supports multi-document ACID transactions.

### 📦 Basic Terminology:
- **Database:** Container for collections.
- **Collection:** A group of MongoDB documents, similar to a table in SQL.
- **Document:** A record in MongoDB, represented as a BSON object (similar to JSON).
- **Field:** A key-value pair in a document.
- **Index:** A performance optimization to speed up query performance.

### 🔍 Example MongoDB Document:
```json
{
  "_id": ObjectId("661d1c09f456789abc123456"),
  "name": "Alice Johnson",
  "email": "alice@example.com",
  "age": 28,
  "skills": ["JavaScript", "MongoDB", "Node.js"],
  "isActive": true,
  "createdAt": ISODate("2025-04-16T10:15:00Z")
}
```

## 🔗 Mongoose

**Mongoose** is a popular **Object Data Modeling (ODM) library for MongoDB and Node.js**.
It provides a layer of abstraction over MongoDB’s native driver to help developers define models using schemas, enforce structure and validation, and write cleaner, more maintainable code.

### 📌 Why Use Mongoose?
- Adds **schema and structure** to MongoDB’s flexible documents.
- Provides **data validation** at the schema level.
- Simplifies **CRUD (Create, Read, Update, Delete)** operations using methods like `.save()`, `.find()`, `.findById()`, etc.
- Offers powerful **middleware hooks** (e.g., pre-save, post-delete) to run logic at various stages.
- Built-in support for **population** (replacing referenced IDs with full documents).
- Easy integration with Express.js for backend APIs.

### 🛠 Schema Definition Example:
```js
const mongoose = require('mongoose');

const userSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
    trim: true
  },
  email: {
    type: String,
    required: true,
    unique: true,
    lowercase: true
  },
  age: {
    type: Number,
    min: 0
  },
  isActive: {
    type: Boolean,
    default: true
  },
  createdAt: {
    type: Date,
    default: Date.now
  }
});

const User = mongoose.model('User', userSchema);
module.exports = User;
```

### 🔄 Connecting to MongoDB:
```js
const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/myapp', {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => {
  console.log("Connected to MongoDB successfully!");
}).catch((err) => {
  console.error("MongoDB connection error:", err);
});
```

### ⚙️ Common Mongoose Operations:
- **Create a new document:**
```js
const user = new User({ name: "John", email: "john@example.com" });
await user.save();
```
- **Find documents:**
```js
const users = await User.find({ isActive: true });
```
- **Update a document:**
```js
await User.updateOne({ _id: userId }, { $set: { age: 29 } });
```
- **Delete a document:**
```js
await User.deleteOne({ _id: userId });
```

### 🔗 References:
- [MongoDB Official Website](https://www.mongodb.com/)
- [Mongoose Documentation](https://mongoosejs.com/)



# ⚙️ Mac এবং Linux-এ MongoDB Compass এবং NoSQLBooster ইনস্টলেশন গাইড (বাংলা)

## 🧭 MongoDB Compass ইনস্টলেশন (Mac & Linux)

### 🍎 MacOS এর জন্য:
1️⃣ [https://www.mongodb.com/try/download/compass](https://www.mongodb.com/try/download/compass) এই লিংকে যান।
2️⃣ আপনার অপারেটিং সিস্টেম হিসেবে **macOS** সিলেক্ট করুন।
3️⃣ Edition হিসেবে "Stable" রাখুন।
4️⃣ `.dmg` ফাইল ডাউনলোড করুন এবং ডাবল ক্লিক করে ইনস্টল করুন।
5️⃣ অ্যাপস ফোল্ডার থেকে **MongoDB Compass** ওপেন করুন।

### 🐧 Linux (Ubuntu/Debian) এর জন্য:
1️⃣ টার্মিনালে নিচের কমান্ডটি লিখে .deb ফাইল ডাউনলোড করুন:
```bash
wget https://downloads.mongodb.com/compass/mongodb-compass_*.deb
```
2️⃣ তারপর ইনস্টল করুন:
```bash
sudo dpkg -i mongodb-compass_*.deb
sudo apt-get install -f  # প্রয়োজন হলে dependencies ফিক্স করতে
```
3️⃣ এরপর অ্যাপ ড্যাশবোর্ড থেকে **Compass** সার্চ করে চালু করুন।

## 🚀 NoSQLBooster ইনস্টলেশন (Mac & Linux)

### 🍎 MacOS এর জন্য:
1️⃣ [https://nosqlbooster.com/downloads](https://nosqlbooster.com/downloads) লিংকে যান।
2️⃣ macOS এর জন্য `.dmg` ফাইলটি ডাউনলোড করুন।
3️⃣ ডাবল ক্লিক করে ইনস্টল করুন এবং Applications ফোল্ডারে ড্র্যাগ করে রাখুন।
4️⃣ এরপর NoSQLBooster অ্যাপটি চালু করুন।

### 🐧 Linux (Ubuntu/Debian) এর জন্য:
1️⃣ `.deb` ফাইলটি ডাউনলোড করুন [https://nosqlbooster.com/downloads](https://nosqlbooster.com/downloads) থেকে।
2️⃣ টার্মিনালে এই কমান্ড দিন:
```bash
sudo dpkg -i nosqlbooster4mongo-*.deb
sudo apt-get install -f
```
3️⃣ ইনস্টলেশন শেষ হলে, Dash মেনুতে গিয়ে “NoSQLBooster” লিখে ওপেন করুন।

✅ এখন আপনি দুইটি টুল দিয়েই MongoDB ডাটাবেস ব্রাউজ, কুয়েরি এবং মডেল ম্যানেজ করতে পারবেন!

---
ℹ️ **টিপস:** MongoDB Compass ডাটা ব্রাউজ করার জন্য ভিজ্যুয়াল টুল এবং NoSQLBooster উন্নত কুয়েরি, স্ক্রিপ্টিং এবং MongoDB shell পরিচালনার জন্য পারফেক্ট।



# 🚀 Express.js দিয়ে MongoDB Function API উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String
});

const User = mongoose.model('User', userSchema);
```

## 🟢 insertOne - POST API
```js
app.post('/add-user', async (req, res) => {
  const newUser = new User(req.body);
  const savedUser = await newUser.save();
  res.json(savedUser);
});
```

## 🟢 insertMany - POST API
```js
app.post('/add-multiple-users', async (req, res) => {
  const users = await User.insertMany(req.body);
  res.json(users);
});
```

## 🔍 find - GET API (সকল ইউজার)
```js
app.get('/users', async (req, res) => {
  const users = await User.find(); // সব ইউজার
  res.json(users);
});
```

## 🔍 findOne - GET API (নাম দিয়ে খোঁজা)
```js
app.get('/user/:name', async (req, res) => {
  const user = await User.findOne({ name: req.params.name });
  res.json(user);
});
```

## 🎯 Field Filtering / Projection - GET API
```js
app.get('/users/projection', async (req, res) => {
  const filtered = await User.find({}, { name: 1, city: 1, _id: 0 });
  res.json(filtered);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 এই রাউটগুলো সরাসরি Postman, Insomnia, বা React/Frontend থেকে হিট করে MongoDB তে ডেটা Create, Read এবং Filter করা যায়।

✅ চাইলে পরবর্তী ধাপে `update`, `delete`, `query with params`, বা `pagination` দিয়েও আমি এই ফাংশনগুলোকে বাড়াতে পারি।



# 🔍 MongoDB কুয়েরি অপারেটর: $eq, $neq, $gt, $lt, $gte, $lte - Express.js উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String
});

const User = mongoose.model('User', userSchema);
```

## 🟢 $eq (ইক্যুয়াল) - GET API
এটি ব্যবহার করা হয় যখন ডাটা ঠিক মেলানো প্রয়োজন। 
```js
app.get('/users/equal', async (req, res) => {
  const users = await User.find({ age: { $eq: 30 } }); // age 30
  res.json(users);
});
```

## 🟢 $neq (নট ইক্যুয়াল) - GET API
এটি ব্যবহার করা হয় যখন ডাটা মেলানো যাবে না এমন শর্ত দিতে হয়।
```js
app.get('/users/neq', async (req, res) => {
  const users = await User.find({ age: { $neq: 30 } }); // age is not 30
  res.json(users);
});
```

## 🟢 $gt (গ্রেটার দ্যান) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান বড় হতে হবে।
```js
app.get('/users/gt', async (req, res) => {
  const users = await User.find({ age: { $gt: 25 } }); // age greater than 25
  res.json(users);
});
```

## 🟢 $lt (লেস দ্যান) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান ছোট হতে হবে।
```js
app.get('/users/lt', async (req, res) => {
  const users = await User.find({ age: { $lt: 30 } }); // age less than 30
  res.json(users);
});
```

## 🟢 $gte (গ্রেটার দ্যান অর ইক্যুয়াল) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান বড় বা সমান হতে হবে।
```js
app.get('/users/gte', async (req, res) => {
  const users = await User.find({ age: { $gte: 25 } }); // age greater than or equal to 25
  res.json(users);
});
```

## 🟢 $lte (লেস দ্যান অর ইক্যুয়াল) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান ছোট বা সমান হতে হবে।
```js
app.get('/users/lte', async (req, res) => {
  const users = await User.find({ age: { $lte: 30 } }); // age less than or equal to 30
  res.json(users);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 এই কুয়েরি অপারেটরগুলোকে আপনি MongoDB ডাটাবেসের যেকোনো ফিল্ডের উপর ব্যবহার করতে পারেন, এবং সহজে রেঞ্জ/কম্পারিসন ভিত্তিক কুয়েরি করতে পারেন।

✅ পরবর্তী সময়ে আরও জটিল কুয়েরি অপারেটর বা অ্যাগ্রিগেশন সম্পর্কে জানতে চাইলে আমাকে জানান!



# 🔍 MongoDB কুয়েরি অপারেটর: $in, $nin, এবং Implicit AND Condition - Express.js উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String
});

const User = mongoose.model('User', userSchema);
```

## 🟢 $in (ইন) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান একটি নির্দিষ্ট তালিকার মধ্যে হতে হবে।
```js
app.get('/users/in', async (req, res) => {
  const users = await User.find({ city: { $in: ['Dhaka', 'Chittagong'] } }); // city is either Dhaka or Chittagong
  res.json(users);
});
```

## 🟢 $nin (নট ইন) - GET API
এটি ব্যবহার করা হয় যখন ডাটার মান একটি নির্দিষ্ট তালিকার মধ্যে থাকতে পারে না।
```js
app.get('/users/nin', async (req, res) => {
  const users = await User.find({ city: { $nin: ['Dhaka', 'Chittagong'] } }); // city is neither Dhaka nor Chittagong
  res.json(users);
});
```

## 🟢 Implicit AND Condition (অথবা AND কন্ডিশন) - GET API
MongoDB ডিফল্টভাবে একাধিক কন্ডিশন একসাথে "AND" অপারেটর হিসেবে ব্যবহার করে। 
উদাহরণস্বরূপ, আপনি যদি age 30 এর বেশি এবং city Dhaka এর মধ্যে ইউজার খুঁজতে চান, তবে নিচের মত করে কুয়েরি করবেন:

```js
app.get('/users/and', async (req, res) => {
  const users = await User.find({ 
    age: { $gt: 25 }, 
    city: 'Dhaka' 
  }); // AND condition: age > 25 AND city is Dhaka
  res.json(users);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 `$in` এবং `$nin` অপারেটর ব্যবহার করে আপনি একটি নির্দিষ্ট মানের তালিকার ভিত্তিতে কুয়েরি করতে পারবেন, এবং Implicit AND কন্ডিশন দ্বারা সহজেই একাধিক কন্ডিশন একসাথে প্রয়োগ করতে পারবেন।

✅ যদি আরও কুয়েরি অপারেটর বা জটিল কুয়েরি স্ট্রাকচার জানতে চান, যেমন `$or`, `$and` বা অ্যাগ্রিগেশন ব্যবহার, আমাকে জানাবেন!



# 🔍 MongoDB কুয়েরি অপারেটর: $and, $or, Implicit vs Explicit - Express.js উদাহরণ


## 🔗 প্রাথমিক সেটআপ:

```js

const express = require('express');

const mongoose = require('mongoose');


const app = express();

app.use(express.json());


mongoose.connect('mongodb://localhost:27017/mydb', {

  useNewUrlParser: true,

  useUnifiedTopology: true

});


const userSchema = new mongoose.Schema({

  name: String,

  age: Number,

  city: String,

  job: String

});


const User = mongoose.model('User', userSchema);

```


## 🟢 $and (অ্যান্ড) - GET API

$and কন্ডিশন একাধিক কন্ডিশন একসাথে প্রয়োগ করতে ব্যবহৃত হয়। আপনাকে একাধিক শর্ত একসাথে মিলাতে হবে।


```js

app.get('/users/and', async (req, res) => {

  const users = await User.find({

    $and: [

      { age: { $gt: 25 } },    // age > 25

      { city: 'Dhaka' }        // city = Dhaka

    ]

  });

  res.json(users);

});

```


## 🟢 $or (অর) - GET API

$or কন্ডিশন একাধিক শর্তের মধ্যে যে কোন একটি শর্ত সত্য হলে মিলিয়ে দিবে।


```js

app.get('/users/or', async (req, res) => {

  const users = await User.find({

    $or: [

      { age: { $gt: 25 } },    // age > 25

      { city: 'Chittagong' }   // city = Chittagong

    ]

  });

  res.json(users);

});

```


## 🟢 Implicit AND Condition (অথবা AND কন্ডিশন) - GET API

MongoDB ডিফল্টভাবে একাধিক কন্ডিশন ব্যবহার করলে এগুলি "implicit AND condition" হয়ে থাকে, অর্থাৎ আপনাকে **$and** অপারেটর ব্যবহার না করেও একাধিক কন্ডিশন মিলাতে পারবেন।


```js

app.get('/users/implicit-and', async (req, res) => {

  const users = await User.find({

    age: { $gt: 25 },     // age > 25

    city: 'Dhaka'         // city = Dhaka

  });                    // Implicitly AND condition

  res.json(users);

});

```


## 🟢 Explicit AND Condition - GET API

$and কন্ডিশন explicitভাবে দেওয়া হয়, যার মধ্যে একাধিক কন্ডিশন থাকে, এবং আপনাকে যেকোনো দুটি বা তার বেশি শর্ত মিলাতে হয়।


```js

app.get('/users/explicit-and', async (req, res) => {

  const users = await User.find({

    $and: [

      { age: { $gt: 25 } },  // age > 25

      { city: 'Dhaka' }      // city = Dhaka

    ]

  });

  res.json(users);

});

```


## 🟢 Explicit OR Condition - GET API

$or কন্ডিশন explicitভাবে ব্যবহার করতে, যেখানে একাধিক শর্তের মধ্যে যে কোন একটি সত্য হলে মিলিয়ে দিবে।


```js

app.get('/users/explicit-or', async (req, res) => {

  const users = await User.find({

    $or: [

      { age: { $gt: 25 } },    // age > 25

      { city: 'Chittagong' }   // city = Chittagong

    ]

  });

  res.json(users);

});

```


## 🏁 সার্ভার চালানো:

```js

app.listen(5000, () => {

  console.log('Server is running on port 5000');

});

```


---

🔥 **Implicit AND** এবং **Explicit AND** দুটি একই কাজ করে, কিন্তু **Implicit** কন্ডিশন MongoDB ডিফল্টভাবে বোঝে, যেখানে **Explicit** কন্ডিশন সরাসরি `$and` দিয়ে উল্লেখ করতে হয়।


🔥 **Implicit OR** এবং **Explicit OR** কন্ডিশনও একইভাবে কাজ করে, তবে `OR` কন্ডিশনের জন্য `$or` অপারেটর অবশ্যই ব্যবহার করতে হয়।


✅ আরও জটিল কুয়েরি বা অ্যাগ্রিগেশন জানতে চাইলে আমাকে জানাবেন!
``


# 🔍 MongoDB কুয়েরি অপারেটর: $exists, $type, $size, $all, $elemMatch - Express.js উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String,
  skills: [String],          // Array field
  details: {
    hobbies: [String]       // Nested array inside an object
  }
});

const User = mongoose.model('User', userSchema);
```

## 🟢 $exists (এক্সিস্ট) - GET API
এটি ব্যবহার করা হয় যখন আপনি একটি ফিল্ডের অস্তিত্ব চেক করতে চান, অর্থাৎ ফিল্ডটি ডকুমেন্টে আছে কি না।

```js
app.get('/users/exists', async (req, res) => {
  const users = await User.find({ city: { $exists: true } }); // city ফিল্ডটি ডকুমেন্টে আছে কিনা
  res.json(users);
});
```

## 🟢 $type (টাইপ) - GET API
এটি ব্যবহার করা হয় ফিল্ডের ডাটা টাইপ চেক করতে, যেমন স্ট্রিং, নাম্বার ইত্যাদি।

```js
app.get('/users/type', async (req, res) => {
  const users = await User.find({ age: { $type: 'number' } }); // age ফিল্ডটি number টাইপ
  res.json(users);
});
```

## 🟢 $size (সাইজ) - GET API
এটি ব্যবহার করা হয় যখন আপনি কোনো অ্যারের সাইজ চেক করতে চান।

```js
app.get('/users/size', async (req, res) => {
  const users = await User.find({ skills: { $size: 3 } }); // skills অ্যারের সাইজ ৩
  res.json(users);
});
```

## 🟢 $all (অল) - GET API
এটি ব্যবহার করা হয় যখন আপনি অ্যারে ফিল্ডে একাধিক মান চেক করতে চান।

```js
app.get('/users/all', async (req, res) => {
  const users = await User.find({ skills: { $all: ['JavaScript', 'Node.js'] } }); // skills অ্যারেতে JavaScript এবং Node.js দুটি মান থাকতে হবে
  res.json(users);
});
```

## 🟢 $elemMatch (এলিম্যাট ম্যাচ) - GET API
এটি ব্যবহার করা হয় যখন আপনি অ্যারে ফিল্ডের মধ্যে একটি নির্দিষ্ট অবজেক্ট বা উপাদান মিলাতে চান। সাধারণত, nested অ্যারে বা অবজেক্টের জন্য এটি ব্যবহার করা হয়।

```js
app.get('/users/elemmatch', async (req, res) => {
  const users = await User.find({ 
    'details.hobbies': { 
      $elemMatch: { $eq: 'Reading' } 
    }
  }); // hobbies অ্যারে থেকে 'Reading' থাকা ইউজার খুঁজে বের করা
  res.json(users);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$exists** অপারেটর ফিল্ডের অস্তিত্ব চেক করতে ব্যবহার করা হয়, **$type** ডাটা টাইপ চেক করতে, **$size** অ্যারের সাইজ চেক করতে, **$all** অ্যারের মধ্যে সব মানের উপস্থিতি চেক করতে, এবং **$elemMatch** নেস্টেড অ্যারে বা অবজেক্টের মধ্যে শর্ত অনুযায়ী এলিমেন্ট খুঁজতে ব্যবহার হয়।

✅ যদি আরও কোনো কুয়েরি অপারেটর বা জটিল কুয়েরি জানতে চান, আমাকে জানাবেন!



# 🔍 MongoDB কুয়েরি অপারেটর: $set, $addToSet, $push, $unset, $pop, $pull, $pullAll - Express.js উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String,
  skills: [String],          // Array field
  details: {
    hobbies: [String]       // Nested array inside an object
  }
});

const User = mongoose.model('User', userSchema);
```

## 🟢 $set (সেট) - PUT API
এটি ব্যবহার করা হয় কোনো ডকুমেন্টের ফিল্ডের মান আপডেট করতে।

```js
app.put('/users/set', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' }, 
    { $set: { age: 30 } }   // age কে 30 তে আপডেট করা
  );
  res.json(updatedUser);
});
```

## 🟢 $addToSet (অ্যাড টু সেট) - PUT API
এটি ব্যবহার করা হয় কোনো অ্যারে ফিল্ডে নতুন মান যোগ করার জন্য, তবে যেগুলি আগেই রয়েছে তা আর যোগ করা হয় না।

```js
app.put('/users/addtset', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $addToSet: { skills: 'React' } }  // React যদি already না থাকে তবে অ্যারেতে যোগ হবে
  );
  res.json(updatedUser);
});
```

## 🟢 $push (পুশ) - PUT API
এটি ব্যবহার করা হয় কোনো অ্যারে ফিল্ডে নতুন মান যোগ করার জন্য, এবং একই মান একাধিকবার যোগ হতে পারে।

```js
app.put('/users/push', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $push: { skills: 'Node.js' } }  // Node.js যোগ হবে
  );
  res.json(updatedUser);
});
```

## 🟢 $unset (আনসেট) - PUT API
এটি ব্যবহার করা হয় কোনো ফিল্ড মুছে ফেলতে।

```js
app.put('/users/unset', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $unset: { job: '' } }  // job ফিল্ড মুছে ফেলা হবে
  );
  res.json(updatedUser);
});
```

## 🟢 $pop (পপ) - PUT API
এটি ব্যবহার করা হয় কোনো অ্যারে ফিল্ডের প্রথম অথবা শেষ উপাদান মুছে ফেলতে।

```js
app.put('/users/pop', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $pop: { skills: 1 } }  // skills অ্যারে থেকে শেষ উপাদান মুছে ফেলবে (1 = শেষ উপাদান)
  );
  res.json(updatedUser);
});
```

## 🟢 $pull (পুল) - PUT API
এটি ব্যবহার করা হয় কোনো অ্যারে থেকে নির্দিষ্ট মান মুছে ফেলতে।

```js
app.put('/users/pull', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $pull: { skills: 'React' } }  // skills অ্যারে থেকে 'React' মুছে ফেলবে
  );
  res.json(updatedUser);
});
```

## 🟢 $pullAll (পুল অল) - PUT API
এটি ব্যবহার করা হয় কোনো অ্যারে থেকে একাধিক মান একসাথে মুছে ফেলতে।

```js
app.put('/users/pullall', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $pullAll: { skills: ['JavaScript', 'Node.js'] } }  // skills অ্যারে থেকে JavaScript এবং Node.js মুছে ফেলবে
  );
  res.json(updatedUser);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$set** অপারেটর ব্যবহার করে আপনি ফিল্ডের মান আপডেট করতে পারবেন।  
**$addToSet** ব্যবহার করলে অ্যারের মধ্যে কোনো মান যদি আগে থেকেই থাকে, তবে তা পুনরায় যোগ করা হবে না।  
**$push** আপনাকে কোনো অ্যারে ফিল্ডে নতুন মান যোগ করতে সাহায্য করে, তবে এটি পুনরায় একই মান যোগ করতে পারে।  
**$unset** ব্যবহার করলে আপনি কোনো ফিল্ড মুছে ফেলতে পারবেন।  
**$pop** এর মাধ্যমে অ্যারের প্রথম বা শেষ উপাদান মুছে ফেলতে পারবেন।  
**$pull** নির্দিষ্ট মান মুছে ফেলতে সাহায্য করে, এবং **$pullAll** একাধিক মান একসাথে মুছে ফেলতে ব্যবহার হয়।

✅ যদি আরও MongoDB কুয়েরি অপারেটর বা জটিল কুয়েরি শিখতে চান, আমাকে জানাবেন!


# 🔍 MongoDB $set অপারেটর, ডকুমেন্ট মুছে ফেলা এবং কলেকশন ড্রপ - Express.js উদাহরণ

## 🔗 প্রাথমিক সেটআপ:
```js
const express = require('express');
const mongoose = require('mongoose');

const app = express();
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/mydb', {
  useNewUrlParser: true,
  useUnifiedTopology: true
});

const userSchema = new mongoose.Schema({
  name: String,
  age: Number,
  city: String,
  job: String,
  skills: [String],          // Array field
  details: {
    hobbies: [String]       // Nested array inside an object
  }
});

const User = mongoose.model('User', userSchema);
```

## 🟢 $set (সেট) অপারেটর - বিস্তারিত
MongoDB-তে **$set** অপারেটর ব্যবহার করা হয় ডকুমেন্টের একটি বা একাধিক ফিল্ডের মান আপডেট করতে। যদি ফিল্ডটি আগে থেকেই উপস্থিত থাকে, তবে তা আপডেট করা হবে; যদি না থাকে, তবে একটি নতুন ফিল্ড হিসেবে সেট হবে।

### $set অপারেটরের ব্যবহার:
- **$set** ব্যবহার করলে আপনি নির্দিষ্ট ফিল্ডের মান পরিবর্তন করতে পারবেন। এটি **insert** বা **update** উভয় কাজেই ব্যবহার করা যেতে পারে।
- **$set** আপনার ডকুমেন্টের নির্দিষ্ট অংশ পরিবর্তন করে, কিন্তু বাকি ডেটা অপরিবর্তিত রাখে।
- এটি MongoDB ডকুমেন্টে ফিল্ড যোগ, পরিবর্তন বা আপডেটের জন্য খুবই শক্তিশালী এবং সহজ উপায়।

### উদাহরণ:
```js
app.put('/users/set', async (req, res) => {
  const updatedUser = await User.updateOne(
    { name: 'John Doe' },
    { $set: { age: 35, city: 'New York' } } // age ও city আপডেট করা
  );
  res.json(updatedUser);
});
```

### ব্যবহারিক দৃষ্টিভঙ্গি:
- **$set** আপনি যেভাবে চান ফিল্ডটিকে নির্দিষ্ট মানে আপডেট করতে ব্যবহার করতে পারেন। 
- যদি কোনো ফিল্ড ডকুমেন্টে না থাকে, তবে এটি নতুন ফিল্ড যোগ করবে।

## 🟢 ডকুমেন্ট মুছে ফেলা - DELETE অপারেটর
MongoDB তে ডকুমেন্ট মুছে ফেলার জন্য **deleteOne** এবং **deleteMany** অপারেটর ব্যবহার করা হয়।

### deleteOne:
এটি একটি নির্দিষ্ট কন্ডিশন মিলে একটিমাত্র ডকুমেন্ট মুছে ফেলে।

```js
app.delete('/users/delete', async (req, res) => {
  const deletedUser = await User.deleteOne({ name: 'John Doe' }); // John Doe নামের ডকুমেন্ট মুছে ফেলা
  res.json(deletedUser);
});
```

### deleteMany:
এটি একাধিক ডকুমেন্ট মুছে ফেলে, যদি কন্ডিশন মেলে।

```js
app.delete('/users/delete-many', async (req, res) => {
  const deletedUsers = await User.deleteMany({ city: 'Dhaka' }); // Dhaka শহরের সব ডকুমেন্ট মুছে ফেলা
  res.json(deletedUsers);
});
```

## 🟢 কলেকশন ড্রপ - drop() অপারেটর
MongoDB তে একটি পূর্ণ কলেকশন মুছে ফেলতে **drop()** অপারেটর ব্যবহার করা হয়।

### কলেকশন ড্রপ:
এটি পুরো কলেকশনটি মুছে ফেলে, সমস্ত ডকুমেন্ট এবং স্কিমা সহ।

```js
app.delete('/users/drop-collection', async (req, res) => {
  const result = await User.collection.drop(); // 'User' কলেকশন মুছে ফেলা
  res.json({ message: 'Collection dropped successfully', result });
});
```

## 🟢 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$set** অপারেটর দিয়ে আপনি ডকুমেন্টের ফিল্ডের মান আপডেট করতে পারেন, এবং নতুন ফিল্ড যোগ করতে পারেন।
🔥 **deleteOne** এবং **deleteMany** দিয়ে এক বা একাধিক ডকুমেন্ট মুছে ফেলতে পারবেন।
🔥 **drop()** অপারেটর ব্যবহার করে পুরো কলেকশন মুছে ফেলতে পারবেন, তবে এই অপারেশনটি পুরো কলেকশনটির ডেটা মুছে ফেলবে এবং পুনরায় পুনরুদ্ধার করা সম্ভব নয়।

✅ যদি আপনি MongoDB সম্পর্কে আরও শিখতে চান, কুয়েরি অপারেটর বা ম্যানিপুলেশন সম্পর্কে কোনো প্রশ্ন থাকলে জানাবেন!


# 🔍 MongoDB Aggregation Framework - একটি পরিচিতি

## 🟢 MongoDB Aggregation Framework কি?
MongoDB এর **Aggregation Framework** একটি শক্তিশালী টুল যা আপনাকে ডেটা ট্রান্সফর্ম, প্রক্রিয়া, এবং বিশ্লেষণ করতে সাহায্য করে। এটি সাধারণত খুবই কার্যকরী যখন আপনি ডেটার উপর বিভিন্ন ধরনের **গ্রুপিং**, **ফিল্টারিং**, **সোর্সিং**, **অর্ডারিং**, এবং **ম্যাপিং** করতে চান।

MongoDB-এর ডাটাবেসে অনেকগুলো ডকুমেন্ট থাকতে পারে এবং আপনি যদি একাধিক ডকুমেন্টের উপর অগ্রাধিকার সহ নির্দিষ্ট ধরনের অপারেশন করতে চান, তবে Aggregation Framework খুবই কার্যকর।

## 🟢 Aggregation Framework এর মূল উপাদান:
MongoDB-এর Aggregation Framework প্রধানত বিভিন্ন ধরনের **stage** (ধাপ) নিয়ে গঠিত। প্রতিটি stage ডেটা ট্রান্সফর্মের একটি নির্দিষ্ট কাজ করে এবং এইগুলো একে অপরের সাথে যুক্ত হয়ে একটি পাইপলাইন তৈরি করে।

### 주요 Aggregate Stages:
- **$match:** একটি stage যা ডকুমেন্টগুলিকে নির্দিষ্ট শর্ত অনুযায়ী ফিল্টার করে।
- **$group:** ডেটাকে গ্রুপ করতে ব্যবহৃত হয়, যেমন `sum`, `avg`, `max`, `min` ইত্যাদি।
- **$project:** ডেটার প্রপার্টি নির্বাচন বা ম্যানিপুলেশন করার জন্য ব্যবহার করা হয়।
- **$sort:** ডেটাকে একটি নির্দিষ্ট ক্রমে সাজানোর জন্য ব্যবহৃত হয়।
- **$limit:** ডেটার সংখ্যা সীমাবদ্ধ করতে ব্যবহৃত হয়।
- **$skip:** ডেটার শুরু থেকে নির্দিষ্ট সংখ্যক ডকুমেন্ট এড়িয়ে যেতে ব্যবহৃত হয়।
- **$unwind:** অ্যারে ফিল্ডগুলিকে পৃথক পৃথক ডকুমেন্টে বিভক্ত করার জন্য ব্যবহৃত হয়।
- **$lookup:** দুটি ভিন্ন কলেকশনের মধ্যে জোড় বা join করার জন্য ব্যবহৃত হয়।

## 🟢 Aggregation Framework-এর উদাহরণ:

### উদাহরণ 1: $match এবং $group
এখানে আমরা `age` এর ভিত্তিতে ব্যবহারকারীদের গ্রুপ করে তাদের গড় বয়স বের করতে চাই।

```js
app.get('/aggregation/avg-age', async (req, res) => {
  const result = await User.aggregate([
    { $match: { city: 'Dhaka' } },       // Dhaka শহরের ব্যবহারকারীদের ফিল্টার
    { $group: { _id: null, avgAge: { $avg: '$age' } } }  // গড় বয়স বের করা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $project
এখানে আমরা `name` এবং `age` ছাড়া অন্যান্য ফিল্ডগুলো বাদ দিয়ে ফিল্টার করতে চাই।

```js
app.get('/aggregation/project', async (req, res) => {
  const result = await User.aggregate([
    { $project: { name: 1, age: 1 } }   // শুধু name এবং age প্রদর্শন করা
  ]);
  res.json(result);
});
```

### উদাহরণ 3: $sort এবং $limit
এখানে আমরা `age` এর ওপর ভিত্তি করে সবচেয়ে বয়সী 5 ব্যবহারকারীকে দেখতে চাই।

```js
app.get('/aggregation/sort-limit', async (req, res) => {
  const result = await User.aggregate([
    { $sort: { age: -1 } },       // বয়স descending order এ সাজানো
    { $limit: 5 }                 // প্রথম 5 ব্যবহারকারী দেখানো
  ]);
  res.json(result);
});
```

### উদাহরণ 4: $unwind
এখানে আমরা একটি অ্যারে ফিল্ড `hobbies` কে প্রতিটি হবি হিসেবে আলাদা ডকুমেন্টে দেখতে চাই।

```js
app.get('/aggregation/unwind', async (req, res) => {
  const result = await User.aggregate([
    { $unwind: '$details.hobbies' }   // hobbies অ্যারেটি পৃথক পৃথক ডকুমেন্টে বিভক্ত
  ]);
  res.json(result);
});
```

### উদাহরণ 5: $lookup (Join)
এখানে আমরা দুটি কলেকশন, `users` এবং `orders`, জোড়া করে ব্যবহারকারী এবং তাদের অর্ডার সম্পর্কিত তথ্য একসাথে আনতে চাই।

```js
app.get('/aggregation/lookup', async (req, res) => {
  const result = await User.aggregate([
    { $lookup: {
      from: 'orders',                // orders কলেকশন থেকে ডেটা নিয়ে আসা
      localField: '_id',             // localField ব্যবহারকারী ID
      foreignField: 'userId',        // foreignField অর্ডার ব্যবহারকারীর ID
      as: 'userOrders'               // ফাইনাল রেজাল্টে যুক্ত করা হবে 'userOrders' নামে
    } }
  ]);
  res.json(result);
});
```

## 🟢 MongoDB Aggregation Framework-এর উপকারিতা:
- **শক্তিশালী ডেটা প্রসেসিং:** এটি অনেক জটিল ডেটা প্রক্রিয়া খুব সহজভাবে সম্পাদন করতে সাহায্য করে।
- **কাস্টম কুয়েরি অপারেশন:** কাস্টম গ্রুপিং, ফিল্টারিং, এবং ট্রান্সফর্মেশন সম্ভব।
- **প্রফর্মেন্স:** MongoDB-এর aggregation স্টেজগুলি অত্যন্ত দক্ষ এবং দ্রুত পারফর্ম করে, বিশেষ করে বড় ডেটা সেটের জন্য।
- **জয়েন:** MongoDB aggregation framework `join` সমর্থন করে যা একাধিক কলেকশনের মধ্যে সম্পর্ক তৈরি করতে সাহায্য করে।

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **Aggregation Framework** MongoDB-তে ডেটা প্রসেসিংয়ের একটি শক্তিশালী পদ্ধতি যা ডেটাকে গ্রুপ, ফিল্টার, সোর্স, সাজানো, এবং পরিবর্তন করার সুযোগ দেয়। এটি অনেক বেশি কার্যকর যখন আপনি জটিল কুয়েরি এবং ডেটা বিশ্লেষণ করতে চান।


# 🔍 MongoDB Aggregation Framework - $match এবং $project স্টেজ

## 🟢 $match স্টেজ
**$match** স্টেজ MongoDB Aggregation Framework-এর প্রথম স্টেজ হিসেবে ব্যবহৃত হয় এবং এটি ডেটার ফিল্টার করার জন্য ব্যবহৃত হয়। এটি মূলত **find()** কুয়েরি ফাংশনের মতোই কাজ করে, কিন্তু এখানে এটি aggregation pipeline-এর অংশ হিসেবে কাজ করে।

- **$match** স্টেজের মাধ্যমে আপনি ডকুমেন্টগুলো ফিল্টার করে শুধুমাত্র সেই ডকুমেন্টগুলো নির্বাচন করতে পারেন যা নির্দিষ্ট শর্ত পূর্ণ করে। 
- আপনি **$match** স্টেজে যে কন্ডিশন দেবেন, তা **find()** কুয়েরির মতোই হতে পারে (যেমন: `$eq`, `$gt`, `$lt`, `$in`, `$and` ইত্যাদি)।
- **$match** স্টেজ সাধারণত aggregation pipeline-এর প্রথমে ব্যবহার করা হয়, তবে এটা যে কোনো জায়গায় ব্যবহার করা যেতে পারে।

### উদাহরণ 1: $match - একক শর্তে ডকুমেন্ট ফিল্টার
এই উদাহরণে আমরা `age` এর ভিত্তিতে ফিল্টার করছি, যাতে ৩০ এর বেশি বয়সের ব্যবহারকারীদের পাওয়া যায়।

```js
app.get('/aggregation/match', async (req, res) => {
  const result = await User.aggregate([
    { $match: { age: { $gt: 30 } } }  // বয়স ৩০ এর বেশি
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $match - একাধিক শর্তে ডকুমেন্ট ফিল্টার
এখানে আমরা `age` এবং `city` এর ভিত্তিতে ডকুমেন্ট ফিল্টার করছি।

```js
app.get('/aggregation/match-multiple', async (req, res) => {
  const result = await User.aggregate([
    { $match: { age: { $gt: 30 }, city: 'Dhaka' } }  // বয়স ৩০ এর বেশি এবং শহর Dhaka
  ]);
  res.json(result);
});
```

## 🟢 $project স্টেজ
**$project** স্টেজ MongoDB Aggregation Framework-এর একটি গুরুত্বপূর্ণ স্টেজ, যা ডকুমেন্টের ফিল্ডগুলোকে নিয়ন্ত্রণ এবং পরিবর্তন করার জন্য ব্যবহৃত হয়। এটি ডকুমেন্টের ফিল্ডগুলোকে নির্বাচিত করে, নতুন ফিল্ড তৈরি করে বা এক্সপ্রেশন ব্যবহার করে তাদের পরিবর্তন করে।

- **$project** স্টেজের মাধ্যমে আপনি ডকুমেন্টে কোন কোন ফিল্ড থাকবে তা নিয়ন্ত্রণ করতে পারেন। আপনি চাইলে কিছু ফিল্ড বাদ দিতে পারেন অথবা নতুন ফিল্ড যুক্ত করতে পারেন।
- আপনি **$project** স্টেজে **0 বা 1** ব্যবহার করে ফিল্ডগুলো ইনক্লুড বা এক্সক্লুড করতে পারেন।
- আপনি **$project** স্টেজে অ্যারেগেট ইক্সপ্রেশনও ব্যবহার করতে পারেন, যেমন: `$add`, `$subtract`, `$multiply`, `$concat` ইত্যাদি।

### উদাহরণ 1: $project - নির্দিষ্ট ফিল্ড নির্বাচন
এখানে আমরা শুধু `name` এবং `age` ফিল্ডগুলো ফিরিয়ে দিচ্ছি এবং অন্য সব ফিল্ড বাদ দিচ্ছি।

```js
app.get('/aggregation/project', async (req, res) => {
  const result = await User.aggregate([
    { $project: { name: 1, age: 1 } }   // শুধু name এবং age ফিল্ড দেখানো
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $project - নতুন ফিল্ড তৈরি করা
এখানে আমরা `fullName` নামক একটি নতুন ফিল্ড তৈরি করেছি যা `firstName` এবং `lastName` ফিল্ডের মানকে যুক্ত করছে।

```js
app.get('/aggregation/project-new-field', async (req, res) => {
  const result = await User.aggregate([
    { $project: { 
        fullName: { $concat: ['$firstName', ' ', '$lastName'] },  // firstName এবং lastName মিশিয়ে fullName তৈরি
        age: 1,  // শুধু age ফিল্ড প্রদর্শন
    } }
  ]);
  res.json(result);
});
```

### উদাহরণ 3: $project - ফিল্ড বাদ দেয়া
এখানে আমরা `city` ফিল্ডটি বাদ দিয়ে বাকি সব ফিল্ড নিয়ে আসছি।

```js
app.get('/aggregation/project-exclude', async (req, res) => {
  const result = await User.aggregate([
    { $project: { city: 0 } }   // city ফিল্ড বাদ দেয়া
  ]);
  res.json(result);
});
```

## 🟢 $match এবং $project একত্রে ব্যবহার
**$match** এবং **$project** স্টেজ একসাথে ব্যবহার করে আপনি প্রথমে ডেটা ফিল্টার করতে পারেন এবং তারপর প্রয়োজনীয় ফিল্ডগুলো নির্বাচন করতে পারেন।

### উদাহরণ: $match এবং $project একসাথে ব্যবহার
এখানে আমরা প্রথমে `age` এর ভিত্তিতে ডকুমেন্ট ফিল্টার করব এবং তারপর `name` এবং `age` ফিল্ডগুলো দেখাবো।

```js
app.get('/aggregation/match-project', async (req, res) => {
  const result = await User.aggregate([
    { $match: { age: { $gt: 30 } } },  // বয়স ৩০ এর বেশি
    { $project: { name: 1, age: 1 } }  // শুধু name এবং age ফিল্ড দেখানো
  ]);
  res.json(result);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$match** স্টেজ MongoDB তে ডেটা ফিল্টার করার জন্য ব্যবহার হয়। এটি ডকুমেন্টগুলিকে নির্দিষ্ট শর্তের ভিত্তিতে নির্বাচন করে।
🔥 **$project** স্টেজ MongoDB তে ডেটার ফিল্ডগুলোকে নির্বাচন, পরিবর্তন বা বাদ দেওয়ার জন্য ব্যবহার হয়।
🔥 আপনি **$match** এবং **$project** স্টেজ একসাথে ব্যবহার করে ডেটার ফিল্টার এবং মান পরিবর্তন করতে পারেন।



# 🔍 MongoDB Aggregation Framework - $addFields, $out এবং $merge স্টেজ

## 🟢 $addFields স্টেজ
**$addFields** স্টেজ MongoDB Aggregation Framework-এ ডকুমেন্টে নতুন ফিল্ড যোগ করার জন্য ব্যবহৃত হয়। এটি একটি নতুন ফিল্ড তৈরি করতে বা বিদ্যমান ফিল্ডের মান আপডেট করতে ব্যবহার করা হয়। এটি সাধারণত **$project** স্টেজের মতো কাজ করে, তবে $addFields বিদ্যমান ডেটার মধ্যে নতুন ফিল্ড যোগ করতে সাহায্য করে।

- **$addFields** ডকুমেন্টে একটি বা একাধিক নতুন ফিল্ড যোগ করতে পারে।
- আপনি ক্যালকুলেশন, এক্সপ্রেশন, বা কোনো ডেটার উপর ভিত্তি করে নতুন ফিল্ড যোগ করতে পারেন।

### উদাহরণ 1: $addFields - নতুন ফিল্ড যোগ
এখানে আমরা একটি নতুন ফিল্ড `fullName` তৈরি করছি যা `firstName` এবং `lastName` ফিল্ডের মানকে যুক্ত করছে।

```js
app.get('/aggregation/addfields', async (req, res) => {
  const result = await User.aggregate([
    { $addFields: { fullName: { $concat: ['$firstName', ' ', '$lastName'] } } } // firstName ও lastName যুক্ত করে fullName তৈরি
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $addFields - বিদ্যমান ফিল্ড পরিবর্তন
এখানে আমরা `age` ফিল্ডের মানে ৫ বছর যোগ করে একটি নতুন ফিল্ড `newAge` তৈরি করছি।

```js
app.get('/aggregation/addfields-age', async (req, res) => {
  const result = await User.aggregate([
    { $addFields: { newAge: { $add: ['$age', 5] } } }  // age এর সাথে ৫ বছর যোগ করে newAge তৈরি
  ]);
  res.json(result);
});
```

## 🟢 $out স্টেজ
**$out** স্টেজ MongoDB Aggregation Framework-এ ডেটার রেজাল্ট সরাসরি একটি নতুন বা বিদ্যমান কলেকশনে লেখা হয়। এটি একটি শেষ স্টেজ হিসেবে ব্যবহৃত হয় এবং এর মাধ্যমে আপনি যেকোনো aggregation pipeline এর রেজাল্ট কে একটি কলেকশনে **write** করতে পারবেন।

- **$out** ব্যবহার করলে আপনি পিপলাইনের শেষের ডেটা সরাসরি একটি কলেকশনে লেখার সুযোগ পাবেন।
- এটি সাধারনত ডেটা প্রক্রিয়াজাত করার পর তা ডাটাবেসে সংরক্ষণ করতে ব্যবহৃত হয়।

### উদাহরণ: $out - নতুন কলেকশনে রেজাল্ট লেখা
এখানে আমরা সমস্ত `User` ডকুমেন্টকে `user_results` নামক একটি নতুন কলেকশনে লিখে ফেলছি।

```js
app.get('/aggregation/out', async (req, res) => {
  const result = await User.aggregate([
    { $match: { city: 'Dhaka' } },   // Dhaka শহরের ব্যবহারকারীদের নির্বাচন
    { $out: 'user_results' }         // user_results কলেকশনে রেজাল্ট সংরক্ষণ
  ]);
  res.json({ message: 'Data written to user_results collection' });
});
```

- **$out** স্টেজ ব্যবহার করলে আগের কলেকশনটি ডিলিট হতে পারে বা পুরোপুরি নতুন কলেকশন তৈরি হতে পারে।
- **$out** সাধারণত ডেটা আর্কাইভ, রিপোর্ট বা বিশ্লেষণের জন্য ব্যবহৃত হয়।

## 🟢 $merge স্টেজ
**$merge** স্টেজ MongoDB-এর **$out** স্টেজের মতো কাজ করে, তবে এটি আরও ফ্লেক্সিবল এবং কার্যকরী। এটি আপনাকে ডেটাকে একটি কলেকশনে মর্জ করার জন্য বিভিন্ন ধরনের অপশন প্রদান করে। এর মাধ্যমে আপনি ডেটা **update**, **insert**, বা **replace** করতে পারেন।

- **$merge** স্টেজটি MongoDB 4.2 বা তার পরের সংস্করণে উপলব্ধ।
- এটি একটি কলেকশনে ডেটা মর্জ, আপডেট বা রিপ্লেস করতে সক্ষম। উদাহরণস্বরূপ, আপনি একই ডকুমেন্টের উপর নতুন ডেটা আপডেট করতে বা নতুন ডকুমেন্ট যোগ করতে পারবেন।

### উদাহরণ: $merge - কলেকশনে ডেটা মর্জ করা
এখানে আমরা `User` কলেকশন থেকে ডেটা নিয়ে `user_final` নামক কলেকশনে মর্জ করছি, যেখানে যদি একই ডকুমেন্ট পাওয়া যায়, তবে তা আপডেট হবে।

```js
app.get('/aggregation/merge', async (req, res) => {
  const result = await User.aggregate([
    { $match: { city: 'Dhaka' } },    // Dhaka শহরের ব্যবহারকারীদের নির্বাচন
    { $merge: { into: 'user_final', whenMatched: 'merge', whenNotMatched: 'insert' } }  // মর্জ করা এবং না পাওয়া গেলে নতুন ডকুমেন্ট যোগ করা
  ]);
  res.json({ message: 'Data merged into user_final collection' });
});
```

- **whenMatched:** এখানে আপনি কিভাবে মেচিং ডকুমেন্টের সাথে কাজ করবেন তা নির্ধারণ করতে পারেন, যেমন: `'merge'`, `'replace'`, `'keepExisting'` ইত্যাদি।
- **whenNotMatched:** এখানে আপনি নতুন ডকুমেন্ট যখন মেলে না তখন কী করতে চান তা নির্বাচন করতে পারেন, যেমন: `'insert'`, `'discard'` ইত্যাদি।

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$addFields** স্টেজ নতুন ফিল্ড যোগ করার জন্য ব্যবহৃত হয় এবং বিদ্যমান ফিল্ড পরিবর্তন করতে সাহায্য করে।
🔥 **$out** স্টেজ ডেটা সরাসরি একটি কলেকশনে লেখার জন্য ব্যবহৃত হয় এবং এটি একটি শেষ স্টেজ।
🔥 **$merge** স্টেজ $out এর মতোই, তবে এটি ডেটার মর্জ বা আপডেট করার জন্য আরও ফ্লেক্সিবল অপশন দেয়।



# 🔍 MongoDB Aggregation Framework - $group, $sum, এবং $push স্টেজ

## 🟢 $group স্টেজ
**$group** স্টেজ MongoDB Aggregation Framework-এ ডেটা গ্রুপ করার জন্য ব্যবহৃত হয়। এটি সাধারণত কিছু নির্দিষ্ট ফিল্ডের উপর ভিত্তি করে ডকুমেন্টগুলোকে গ্রুপ করতে ব্যবহার করা হয় এবং গ্রুপিং করার পর বিভিন্ন অ্যাগ্রিগেট ফাংশন প্রয়োগ করতে পারেন, যেমন: **$sum**, **$avg**, **$max**, **$min** ইত্যাদি।

- **$group** স্টেজের মাধ্যমে আপনি এক বা একাধিক ফিল্ডের ভিত্তিতে ডেটাকে গ্রুপ করতে পারবেন।
- এটি প্রতিটি গ্রুপের জন্য একটি নতুন ডকুমেন্ট তৈরি করে।

### উদাহরণ 1: $group - গ্রুপিং বয়স অনুযায়ী
এখানে আমরা `age` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি বয়সের জন্য মোট ব্যবহারকারীর সংখ্যা গণনা করছি।

```js
app.get('/aggregation/group', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$age', totalUsers: { $sum: 1 } } }  // age অনুযায়ী গ্রুপিং এবং মোট ব্যবহারকারী সংখ্যা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $group - গ্রুপিং এবং সর্বোচ্চ বয়স বের করা
এখানে আমরা `city` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি শহরের সর্বোচ্চ বয়স বের করছি।

```js
app.get('/aggregation/group-max-age', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$city', maxAge: { $max: '$age' } } }  // city অনুযায়ী গ্রুপিং এবং max age বের করা
  ]);
  res.json(result);
});
```

## 🟢 $sum স্টেজ
**$sum** স্টেজ MongoDB Aggregation Framework-এ একটি অ্যাগ্রিগেট ফাংশন যা গ্রুপিং করার পর কোন ফিল্ডের মান যোগ করার জন্য ব্যবহৃত হয়। এটি সাধারণত **$group** স্টেজের ভিতরে ব্যবহৃত হয়।

- **$sum** স্টেজ গ্রুপের প্রতিটি ডকুমেন্টের নির্দিষ্ট ফিল্ডের মান যোগ করতে সাহায্য করে।
- এটি একাধিক ডকুমেন্টের মান যোগ বা গুন করার জন্য ব্যবহার করা যায়।

### উদাহরণ 1: $sum - মোট বয়সের যোগফল
এখানে আমরা `age` ফিল্ডের মান যোগ করে মোট বয়সের যোগফল বের করছি।

```js
app.get('/aggregation/sum', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: null, totalAge: { $sum: '$age' } } }  // সকল ব্যবহারকারীর বয়স যোগ করা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $sum - নির্দিষ্ট শর্তে যোগফল
এখানে আমরা শুধু `age` এর ভিত্তিতে শর্ত পূর্ণ হলে মোট বয়সের যোগফল বের করছি।

```js
app.get('/aggregation/sum-condition', async (req, res) => {
  const result = await User.aggregate([
    { $match: { city: 'Dhaka' } },   // Dhaka শহরের ব্যবহারকারীরা
    { $group: { _id: null, totalAge: { $sum: '$age' } } }  // Dhaka শহরের ব্যবহারকারীদের বয়সের যোগফল
  ]);
  res.json(result);
});
```

## 🟢 $push স্টেজ
**$push** স্টেজ MongoDB Aggregation Framework-এ ব্যবহৃত হয় ডকুমেন্টগুলোকে একটি অ্যারে হিসেবে সাজানোর জন্য। এটি সাধারণত **$group** স্টেজের সাথে ব্যবহৃত হয় যাতে একাধিক ডকুমেন্টের মান একটি অ্যারেতে একত্রিত করা যায়।

- **$push** স্টেজ একটি অ্যারে তৈরি করে, যা গ্রুপের ভিতরে থাকা ডকুমেন্টের মানগুলো ধারণ করবে।
- এটি ডকুমেন্টের কোনো নির্দিষ্ট ফিল্ডের মান বা পুরো ডকুমেন্টের অ্যারে তৈরি করতে ব্যবহার করা যেতে পারে।

### উদাহরণ 1: $push - ব্যবহারকারীদের নামের অ্যারে তৈরি
এখানে আমরা `city` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি শহরের সকল ব্যবহারকারীর নামের একটি অ্যারে তৈরি করছি।

```js
app.get('/aggregation/push', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$city', users: { $push: '$name' } } }  // city অনুযায়ী গ্রুপিং এবং users অ্যারে তৈরি
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $push - কাস্টম ফিল্ডের অ্যারে তৈরি
এখানে আমরা `age` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি বয়সের জন্য একটি কাস্টম ফিল্ডের অ্যারে তৈরি করছি।

```js
app.get('/aggregation/push-custom', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$age', usersInfo: { $push: { name: '$name', city: '$city' } } } }  // age অনুযায়ী গ্রুপিং এবং name ও city এর অ্যারে তৈরি
  ]);
  res.json(result);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$group** স্টেজ MongoDB তে ডেটা গ্রুপ করার জন্য ব্যবহৃত হয়, যেমন: বয়স, শহর, বা অন্যান্য কাস্টম শর্তে।
🔥 **$sum** স্টেজ গ্রুপের ভিতরে নির্দিষ্ট ফিল্ডের মান যোগ করতে ব্যবহৃত হয়, যেমন: বয়সের যোগফল বা অন্য কোন সংখ্যার যোগফল।
🔥 **$push** স্টেজ একটি অ্যারে তৈরি করে যা গ্রুপের ভিতরে থাকা ফিল্ডের মানগুলোকে ধারণ করে। এটি ব্যবহারকারীদের নাম বা অন্য কাস্টম ডেটার অ্যারে তৈরি করতে ব্যবহৃত হয়।



# 🔍 MongoDB Aggregation Framework - $group এবং $project স্টেজ

## 🟢 $group স্টেজ
**$group** স্টেজ MongoDB Aggregation Framework-এ ডেটা গ্রুপ করতে ব্যবহৃত হয়। এটি বিভিন্ন ডকুমেন্টকে একটি নির্দিষ্ট ফিল্ডের ভিত্তিতে গ্রুপ করে এবং প্রতিটি গ্রুপের উপর অ্যাগ্রিগেট ফাংশন প্রয়োগ করার সুযোগ দেয়। যেমন, আপনি একাধিক ডকুমেন্টের মান যোগ করতে, গড় বের করতে, সর্বোচ্চ বা সর্বনিম্ন মান বের করতে পারেন।

- **$group** স্টেজ গ্রুপিং করার পর অ্যাগ্রিগেট ফাংশন ব্যবহার করে বিভিন্ন তথ্য বের করার জন্য সাহায্য করে।
- **$group** স্টেজে **_id** ফিল্ড থাকা বাধ্যতামূলক। এটি গ্রুপিংয়ের জন্য ব্যবহৃত ফিল্ড বা একাধিক ফিল্ড হতে পারে।
- **$group** স্টেজের মধ্যে বিভিন্ন অ্যাগ্রিগেট ফাংশন (যেমন, **$sum**, **$avg**, **$max**, **$min**, **$first**, **$last** ইত্যাদি) ব্যবহার করা যায়।

### উদাহরণ 1: $group - নির্দিষ্ট শহরের মধ্যে মোট বয়সের যোগফল বের করা
এখানে আমরা `city` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি শহরের জন্য মোট বয়সের যোগফল বের করছি।

```js
app.get('/aggregation/group-total-age', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$city', totalAge: { $sum: '$age' } } }  // city অনুযায়ী গ্রুপিং এবং মোট বয়সের যোগফল বের করা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $group - সর্বোচ্চ বয়স বের করা
এখানে আমরা `city` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি শহরের সর্বোচ্চ বয়স বের করছি।

```js
app.get('/aggregation/group-max-age', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$city', maxAge: { $max: '$age' } } }  // city অনুযায়ী গ্রুপিং এবং সর্বোচ্চ বয়স বের করা
  ]);
  res.json(result);
});
```

### উদাহরণ 3: $group - ব্যবহারকারীদের নামের অ্যারে তৈরি
এখানে আমরা `city` অনুযায়ী গ্রুপিং করছি এবং প্রতিটি শহরের সকল ব্যবহারকারীর নামের একটি অ্যারে তৈরি করছি।

```js
app.get('/aggregation/group-users', async (req, res) => {
  const result = await User.aggregate([
    { $group: { _id: '$city', users: { $push: '$name' } } }  // city অনুযায়ী গ্রুপিং এবং নামের অ্যারে তৈরি
  ]);
  res.json(result);
});
```

## 🟢 $project স্টেজ
**$project** স্টেজ MongoDB Aggregation Framework-এ ডকুমেন্টের ভেতরের ফিল্ড গুলোকে অন্তর্ভুক্ত বা বাদ দেয়ার জন্য ব্যবহৃত হয়। এটি সাধারণত একটি ডকুমেন্টের কাঠামো পরিবর্তন করতে ব্যবহৃত হয়, যেমন ফিল্ড গুলি ফিল্টার করা বা নতুন ফিল্ড তৈরি করা।

- **$project** স্টেজের মাধ্যমে আপনি শুধুমাত্র নির্দিষ্ট ফিল্ডগুলো নির্বাচন করতে পারবেন এবং বাকি ফিল্ডগুলো বাদ দিতে পারবেন।
- এটি ফিল্ডের মান পরিবর্তন করতে, নতুন ফিল্ড তৈরি করতে বা বিদ্যমান ফিল্ডের মান কাস্টমাইজ করতে সাহায্য করে।
- আপনি **0** বা **1** ব্যবহার করে ফিল্ড ইনক্লুড বা এক্সক্লুড করতে পারেন।

### উদাহরণ 1: $project - নির্দিষ্ট ফিল্ড গুলি সিলেক্ট করা
এখানে আমরা `name` এবং `age` ফিল্ডকে সিলেক্ট করছি এবং বাকি ফিল্ডগুলো বাদ দিচ্ছি।

```js
app.get('/aggregation/project', async (req, res) => {
  const result = await User.aggregate([
    { $project: { name: 1, age: 1 } }  // name এবং age সিলেক্ট করা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $project - নতুন ফিল্ড তৈরি করা
এখানে আমরা `firstName` এবং `lastName` থেকে `fullName` নামে একটি নতুন ফিল্ড তৈরি করছি।

```js
app.get('/aggregation/project-fullname', async (req, res) => {
  const result = await User.aggregate([
    { $project: { fullName: { $concat: ['$firstName', ' ', '$lastName'] } } }  // firstName এবং lastName থেকে fullName তৈরি
  ]);
  res.json(result);
});
```

### উদাহরণ 3: $project - ফিল্ড মান কাস্টমাইজ করা
এখানে আমরা `age` ফিল্ডের মান ৫ বছর বাড়িয়ে একটি নতুন ফিল্ড `newAge` তৈরি করছি।

```js
app.get('/aggregation/project-age', async (req, res) => {
  const result = await User.aggregate([
    { $project: { newAge: { $add: ['$age', 5] }, name: 1 } }  // age এ ৫ বছর যোগ করে newAge তৈরি
  ]);
  res.json(result);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$group** স্টেজ MongoDB তে ডেটা গ্রুপ করার জন্য ব্যবহৃত হয়, যেমন: বয়স, শহর, বা অন্যান্য কাস্টম শর্তে।
🔥 **$sum**, **$avg**, **$max**, **$min** ইত্যাদি অ্যাগ্রিগেট ফাংশন **$group** স্টেজের মধ্যে ব্যবহৃত হয়।
🔥 **$project** স্টেজ MongoDB তে ডকুমেন্টের ফিল্ড গুলি সিলেক্ট, বাদ দেওয়া বা নতুন ফিল্ড তৈরি করতে ব্যবহৃত হয়।
🔥 **$project** ফিল্ড মান কাস্টমাইজ করার জন্যও ব্যবহার করা যায়, যেমন: যোগফল, এক্সপ্রেশন ব্যবহার করা ইত্যাদি।



# 🔍 MongoDB Aggregation Framework - $bucket, $sort, এবং $limit স্টেজ

## 🟢 $bucket স্টেজ
**$bucket** স্টেজ MongoDB Aggregation Framework-এ ডেটাকে নির্দিষ্ট পরিসরের মধ্যে ভাগ করতে ব্যবহৃত হয়। এটি মূলত একটি "bucket" তৈরি করে এবং বিভিন্ন ডকুমেন্টকে সেই "bucket"-এর মধ্যে বিতরণ করে। সাধারণত এটি রেঞ্জ ভিত্তিক গ্রুপিং করার জন্য ব্যবহৃত হয়।

- **$bucket** স্টেজে **boundaries** (সীমা) নির্দিষ্ট করা হয়, যেগুলোর মধ্যে ডকুমেন্টগুলো ভাগ হবে।
- **$bucket** ব্যবহার করে আপনি ডকুমেন্টগুলোর মধ্যে কোন নির্দিষ্ট মানের রেঞ্জ অনুযায়ী গ্রুপ করতে পারবেন।

### উদাহরণ 1: $bucket - বয়সের রেঞ্জে গ্রুপিং
এখানে আমরা `age` অনুযায়ী বয়সের রেঞ্জ (যেমন: 0-20, 21-40, 41-60) তৈরি করছি এবং প্রতিটি রেঞ্জে কতজন ব্যবহারকারী রয়েছে তা গণনা করছি।

```js
app.get('/aggregation/bucket-age', async (req, res) => {
  const result = await User.aggregate([
    { 
      $bucket: {
        groupBy: '$age',  // যে ফিল্ডে গ্রুপিং করতে হবে (এখানে age)
        boundaries: [0, 20, 40, 60, 80],  // বয়সের রেঞ্জ
        default: 'Other',  // যদি age কোন রেঞ্জে না আসে, তাহলে 'Other' হিসেবে ক্যাটেগরাইজ করা হবে
        output: { 
          count: { $sum: 1 }  // প্রতিটি রেঞ্জে কতজন ব্যবহারকারী রয়েছে তা গণনা করা
        }
      }
    }
  ]);
  res.json(result);
});
```

## 🟢 $sort স্টেজ
**$sort** স্টেজ MongoDB Aggregation Framework-এ ডেটা সাজানোর জন্য ব্যবহৃত হয়। এটি নির্দিষ্ট ফিল্ডের উপর ভিত্তি করে ডকুমেন্টগুলো সাজানোর সুযোগ দেয়, যেমন: ক্রমAscending বা Descending-এ সাজানো।

- **$sort** স্টেজে ফিল্ড নাম এবং ক্রম (1 বা -1) নির্ধারণ করা হয়, যেখানে **1** মানে Ascending (ছোট থেকে বড়) এবং **-1** মানে Descending (বড় থেকে ছোট)।
- এটি আপনাকে ডেটা সাজানোর প্রক্রিয়াতে সাহায্য করে, যাতে আপনি ডেটা সবচেয়ে ছোট বা বড় মান অনুসারে সাজাতে পারেন।

### উদাহরণ 1: $sort - বয়স অনুযায়ী সাজানো
এখানে আমরা `age` ফিল্ডের উপর ভিত্তি করে ব্যবহারকারীদের সাজাচ্ছি, প্রথমে Ascending (ছোট থেকে বড়) এবং পরে Descending (বড় থেকে ছোট)।

```js
app.get('/aggregation/sort', async (req, res) => {
  const result = await User.aggregate([
    { $sort: { age: 1 } }  // বয়সের উপর Ascending (ছোট থেকে বড়) অনুসারে সাজানো
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $sort - বয়সের ভিত্তিতে Descending (বড় থেকে ছোট) সাজানো
এখানে আমরা `age` ফিল্ডের উপর ভিত্তি করে ব্যবহারকারীদের সাজাচ্ছি, তবে এইবার Descending (বড় থেকে ছোট) ক্রমে।

```js
app.get('/aggregation/sort-desc', async (req, res) => {
  const result = await User.aggregate([
    { $sort: { age: -1 } }  // বয়সের উপর Descending (বড় থেকে ছোট) অনুসারে সাজানো
  ]);
  res.json(result);
});
```

## 🟢 $limit স্টেজ
**$limit** স্টেজ MongoDB Aggregation Framework-এ ডকুমেন্টের সংখ্যা সীমাবদ্ধ করতে ব্যবহৃত হয়। এটি নির্দিষ্ট সংখ্যা পর্যন্ত ডকুমেন্ট রিটার্ন করতে সাহায্য করে, যাতে আপনি অতিরিক্ত ডেটা রিটার্ন না করেন।

- **$limit** স্টেজ সাধারণত অনেক ডকুমেন্টের মধ্যে থেকে কিছু নির্দিষ্ট ডকুমেন্ট নির্বাচন করতে ব্যবহৃত হয়।
- এটি সবসময় ডকুমেন্টের সংখ্যা সীমাবদ্ধ করতে সাহায্য করে, যেমন: প্রথম ১০টি ডকুমেন্ট বা সর্বোচ্চ ৫টি ডকুমেন্ট।

### উদাহরণ 1: $limit - সর্বোচ্চ ৫টি ডকুমেন্ট রিটার্ন করা
এখানে আমরা সর্বোচ্চ ৫টি ডকুমেন্ট রিটার্ন করছি।

```js
app.get('/aggregation/limit', async (req, res) => {
  const result = await User.aggregate([
    { $limit: 5 }  // প্রথম ৫টি ডকুমেন্ট রিটার্ন করা
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $limit - সর্বোচ্চ ১০টি ডকুমেন্ট রিটার্ন করা এবং তারপর $sort
এখানে আমরা প্রথমে ১০টি ডকুমেন্ট রিটার্ন করছি এবং তারপর সেগুলো বয়সের উপর ভিত্তি করে সাজাচ্ছি।

```js
app.get('/aggregation/limit-sort', async (req, res) => {
  const result = await User.aggregate([
    { $limit: 10 },  // প্রথম ১০টি ডকুমেন্ট রিটার্ন করা
    { $sort: { age: 1 } }  // বয়সের উপর Ascending (ছোট থেকে বড়) সাজানো
  ]);
  res.json(result);
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$bucket** স্টেজ MongoDB তে ডেটাকে নির্দিষ্ট পরিসরের মধ্যে ভাগ করতে ব্যবহৃত হয়, যেমন: বয়সের রেঞ্জে গ্রুপিং করা।
🔥 **$sort** স্টেজ MongoDB তে ডেটা সাজানোর জন্য ব্যবহৃত হয়, যেমন: বয়স বা নাম অনুযায়ী Ascending বা Descending ক্রমে সাজানো।
🔥 **$limit** স্টেজ MongoDB তে ডকুমেন্টের সংখ্যা সীমাবদ্ধ করার জন্য ব্যবহৃত হয়, যেমন: প্রথম ৫টি ডকুমেন্ট রিটার্ন করা।


# 🔍 MongoDB Aggregation Framework - $lookup স্টেজ এবং Embedding vs Referencing

## 🟢 $lookup স্টেজ
**$lookup** স্টেজ MongoDB Aggregation Framework-এ ব্যবহৃত হয় দুটি আলাদা কোলেকশনকে একত্রিত করার জন্য। এটি **join** এর মতো কাজ করে, যেখানে একটি কোলেকশন থেকে ডেটা অন্য কোলেকশনের সাথে সংযুক্ত করা হয়। MongoDB তে `join` সাধারণত একাধিক ডকুমেন্টের মধ্যে সম্পর্ক স্থাপন করার জন্য ব্যবহৃত হয়।

- **$lookup** স্টেজ দুটি কোলেকশনকে **left outer join** এর মাধ্যমে একত্রিত করে। অর্থাৎ, যেই ডকুমেন্টগুলো এক কোলেকশনে উপস্থিত আছে, তাদের সাথে অন্য কোলেকশন থেকে সম্পর্কিত ডেটা যুক্ত হয়।
- এটি **from**, **localField**, **foreignField**, এবং **as** ব্যবহার করে দুটি কোলেকশনকে যুক্ত করে।

### উদাহরণ 1: $lookup - একটি কোলেকশন থেকে আরেকটি কোলেকশনের ডেটা যুক্ত করা
এখানে আমরা `orders` কোলেকশনের `customerId` ফিল্ডের মাধ্যমে `customers` কোলেকশনের ডেটা যুক্ত করছি।

```js
app.get('/aggregation/lookup', async (req, res) => {
  const result = await Order.aggregate([
    { 
      $lookup: {
        from: 'customers',        // যে কোলেকশনটি join করতে হবে (এখানে customers)
        localField: 'customerId',  // current কোলেকশনের ফিল্ড
        foreignField: '_id',       // joining কোলেকশনের ফিল্ড
        as: 'customerDetails'      // নতুন ফিল্ড যেখানে join ডেটা রাখা হবে
      }
    }
  ]);
  res.json(result);
});
```

### উদাহরণ 2: $lookup - একাধিক কোলেকশন থেকে ডেটা যুক্ত করা
এখানে আমরা `orders` কোলেকশন থেকে `customerId` এবং `productId` এর মাধ্যমে যথাক্রমে `customers` এবং `products` কোলেকশনের ডেটা যুক্ত করছি।

```js
app.get('/aggregation/lookup-multiple', async (req, res) => {
  const result = await Order.aggregate([
    { 
      $lookup: {
        from: 'customers',
        localField: 'customerId',
        foreignField: '_id',
        as: 'customerDetails'
      }
    },
    { 
      $lookup: {
        from: 'products',
        localField: 'productId',
        foreignField: '_id',
        as: 'productDetails'
      }
    }
  ]);
  res.json(result);
});
```

## 🟢 Embedding vs Referencing

MongoDB তে ডেটা স্টোর করার দুইটি মূল পদ্ধতি রয়েছে: **Embedding** এবং **Referencing**। এই দুটি পদ্ধতির মধ্যে পার্থক্য হলো ডেটার সংরক্ষণ পদ্ধতি এবং কিভাবে ডেটা অ্যাক্সেস করা হবে।

### 🔵 Embedding
**Embedding** পদ্ধতিতে, ডেটা একটি ডকুমেন্টের ভিতরেই অন্য ডকুমেন্টের তথ্য যুক্ত করা হয়। অর্থাৎ, আপনি ডেটাকে **nested** ভাবে স্টোর করেন। এটি সাধারণত তখন ব্যবহৃত হয়, যখন ডেটার একটি অংশ অপর অংশের সাথে দৃঢ়ভাবে সম্পর্কিত এবং আপনি একই সময়ে একত্রে ডেটা অ্যাক্সেস করতে চান।

- **Pros**:
  - দ্রুত পড়া (Fast reads) কারণ সব ডেটা একত্রে থাকে।
  - অনেক কম join অপারেশন প্রয়োজন।
  - অধিকাংশ ক্ষেত্রে কম query এর প্রয়োজন হয়।

- **Cons**:
  - ডেটা পুনরাবৃত্তি হতে পারে এবং ডিস্ক স্পেসের অপচয় হতে পারে।
  - যদি ডেটা পরিবর্তন করতে হয় তবে ঐ ডকুমেন্টটিকে পুরোপুরি আপডেট করতে হবে।
  - ডেটার সাইজ বড় হলে ডকুমেন্টটি বড় হয়ে যেতে পারে।

#### উদাহরণ: Embedding
এখানে `user` ডকুমেন্টের মধ্যে আমরা `address` স্টোর করছি।

```js
const userSchema = new mongoose.Schema({
  name: String,
  email: String,
  address: {
    street: String,
    city: String,
    zip: String
  }
});
```

### 🔵 Referencing
**Referencing** পদ্ধতিতে, আপনি ডেটার দুটি আলাদা ডকুমেন্ট তৈরি করেন এবং তাদের মধ্যে একটি **reference** রাখেন। অর্থাৎ, একটি ডকুমেন্টে অন্য ডকুমেন্টের **ObjectId** সংরক্ষণ করা হয়, যা পরে প্রয়োজনে একত্রিত করা হয়।

- **Pros**:
  - ডেটা পুনরাবৃত্তি হয় না, তাই ডিস্ক স্পেস সাশ্রয়ী।
  - ডেটা যখন পরিবর্তন হয়, তখন শুধুমাত্র একটি ডকুমেন্ট পরিবর্তন করতে হয়।
  - অনেক বেশি স্কেলেবল (Scalable) কারণ ছোট ডকুমেন্ট ব্যবহার করা হয়।

- **Cons**:
  - একাধিক কোলেকশনকে জুড়তে **join** বা **$lookup** ব্যবহার করা লাগে, যা কিছুটা ধীরগতির হতে পারে।
  - অতিরিক্ত query এর প্রয়োজন হতে পারে।

#### উদাহরণ: Referencing
এখানে `order` ডকুমেন্টে আমরা `productId` এবং `customerId` ফিল্ডের মাধ্যমে অন্য কোলেকশনের ডেটা রেফারেন্স করছি।

```js
const orderSchema = new mongoose.Schema({
  customerId: { type: mongoose.Schema.Types.ObjectId, ref: 'Customer' },
  productId: { type: mongoose.Schema.Types.ObjectId, ref: 'Product' },
  orderDate: Date,
  quantity: Number
});
```

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **$lookup** স্টেজ MongoDB তে দুটি কোলেকশনকে একত্রিত করার জন্য ব্যবহৃত হয়, যেমন: এক কোলেকশনের `customerId` দিয়ে আরেক কোলেকশনের ডেটা যোগ করা।
🔥 **Embedding** পদ্ধতিতে ডেটা এক ডকুমেন্টের মধ্যে রাখা হয় এবং এটি দ্রুত অ্যাক্সেসের জন্য উপকারী।
🔥 **Referencing** পদ্ধতিতে ডেটা আলাদা ডকুমেন্টে রাখা হয় এবং তাদের মধ্যে **ObjectId** দিয়ে সম্পর্ক স্থাপন করা হয়, যা স্কেলেবিলিটির জন্য উপযুক্ত।



# 🔍 MongoDB - Indexing, COLLSCAN vs IXSCAN

## 🟢 Indexing
**Indexing** হল MongoDB-তে ডেটার দ্রুত অ্যাক্সেস নিশ্চিত করার জন্য একটি গুরুত্বপূর্ণ প্রক্রিয়া। যখন একটি কোলেকশনে অনেক ডকুমেন্ট থাকে, তখন ডেটার মধ্যে দ্রুত অনুসন্ধান (search) এবং ফিল্টার করতে ইনডেক্স তৈরি করা হয়। MongoDB ডিফল্টভাবে **COLLSCAN** ব্যবহার করে যদি কোন ইনডেক্স না থাকে, তবে যদি ইনডেক্স থাকে, তবে MongoDB সেই ইনডেক্স ব্যবহার করবে, যা খুবই দ্রুত।

- **Index** একটি ডাটা স্ট্রাকচার (যেমন: B-tree), যা MongoDB-কে দ্রুত ডেটা খুঁজে পেতে সাহায্য করে।
- ইনডেক্স তৈরি করার মাধ্যমে আপনি একটি নির্দিষ্ট ফিল্ডের জন্য **Query Performance** উন্নত করতে পারেন।
- MongoDB বিভিন্ন ধরনের ইনডেক্স সমর্থন করে যেমন **Single Field Index**, **Compound Index**, **Text Index**, **Geospatial Index**, ইত্যাদি।

### উদাহরণ: Single Field Index তৈরি করা
এখানে আমরা `email` ফিল্ডের জন্য একটি ইনডেক্স তৈরি করছি:

```js
UserSchema.index({ email: 1 });  // 1 মানে Ascending Order (ইনডেক্স Ascending অবস্থায় হবে)
```

## 🟢 COLLSCAN (Collection Scan)
**COLLSCAN** হল MongoDB এর একটি পদ্ধতি যেখানে MongoDB কোলেকশনের সমস্ত ডকুমেন্ট পরীক্ষা করে কুয়েরি মেলে কিনা তা নির্ধারণ করতে। এটি তখন ঘটে যখন ইনডেক্স না থাকে এবং MongoDB পুরো কোলেকশন স্ক্যান করে ডেটা খুঁজে বের করে।

- **COLLSCAN** হচ্ছে সবচেয়ে ধীর গতির পদ্ধতি, কারণ MongoDB সমস্ত ডকুমেন্ট একে একে পরীক্ষা করতে থাকে।
- এটা বিশেষত তখন ঘটে যখন আপনি এমন একটি ফিল্ডে কুয়েরি করছেন যার জন্য কোনো ইনডেক্স নেই।

### উদাহরণ: COLLSCAN ঘটে যখন ইনডেক্স নেই
যদি আমরা `User` কোলেকশনে `name` ফিল্ডে কুয়েরি করি, এবং সেখানে কোন ইনডেক্স না থাকে, তখন MongoDB **COLLSCAN** ব্যবহার করবে।

```js
const users = await User.find({ name: 'John' });
```

**COLLSCAN** সব ডকুমেন্ট চেক করবে `name: 'John'` মেলে কিনা তা খুঁজতে।

## 🟢 IXSCAN (Index Scan)
**IXSCAN** হল MongoDB তে যখন ইনডেক্স ব্যবহার করে কুয়েরি প্রক্রিয়াকরণ করা হয়। MongoDB একটি ইনডেক্স স্ক্যান ব্যবহার করে ইনডেক্স ফিল্ডের জন্য দ্রুত ডেটা খুঁজে বের করে। এটি **COLLSCAN** এর চেয়ে অনেক দ্রুত।

- **IXSCAN** MongoDB কেবল ইনডেক্সে সংরক্ষিত ডেটার উপর ভিত্তি করে অনুসন্ধান করে, ফলে ডেটার মধ্যে পুরো কোলেকশন স্ক্যান করার প্রয়োজন হয় না।
- এটি সাধারণত দ্রুত কুয়েরি পারফরম্যান্স প্রদান করে, কারণ MongoDB ইনডেক্সের মাধ্যমে ডেটার অবস্থান সরাসরি জানে।

### উদাহরণ: IXSCAN ঘটে যখন ইনডেক্স আছে
যদি আমাদের `User` কোলেকশনে `email` ফিল্ডের জন্য একটি ইনডেক্স থাকে এবং আমরা `email` ফিল্ডে কুয়েরি করি, তখন MongoDB **IXSCAN** ব্যবহার করবে।

```js
const user = await User.find({ email: 'john@example.com' });
```

এখানে MongoDB ইনডেক্স ব্যবহার করে **IXSCAN** করবে এবং খুব দ্রুত `email: 'john@example.com'` মেলানো ডেটা ফিরিয়ে দেবে।

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **Indexing** MongoDB তে ডেটার দ্রুত অনুসন্ধানের জন্য ব্যবহৃত হয়। এটি MongoDB কে ইনডেক্স ব্যবহার করে ডেটা দ্রুত খুঁজতে সাহায্য করে।
🔥 **COLLSCAN** হল MongoDB এর একটি পদ্ধতি, যেখানে MongoDB সমস্ত ডকুমেন্ট স্ক্যান করে কুয়েরি মেলানোর চেষ্টা করে, যদি ইনডেক্স না থাকে।
🔥 **IXSCAN** MongoDB তে ইনডেক্স ব্যবহার করে দ্রুত ডেটা খুঁজে পাওয়ার পদ্ধতি। এটি **COLLSCAN** এর চেয়ে অনেক দ্রুত।



# 🔍 MongoDB - Compound Index এবং Text Index

## 🟢 Compound Index
**Compound Index** হল এমন একটি ইনডেক্স যা একাধিক ফিল্ডে ইনডেক্স তৈরি করে। MongoDB কেবল একক ফিল্ডের জন্য ইনডেক্স তৈরি করার বদলে একাধিক ফিল্ডের উপর ইনডেক্স তৈরি করতে সহায়তা করে। এটি তখন ব্যবহৃত হয় যখন কুয়েরি একাধিক ফিল্ডে হতে পারে এবং আপনি প্রতিটি ফিল্ডের জন্য আলাদা ইনডেক্স তৈরি করতে চান না।

- **Compound Index** একাধিক ফিল্ডের উপর ইনডেক্স তৈরি করে, যাতে বিভিন্ন ফিল্ডের মধ্যে সম্পর্কিত কুয়েরি দ্রুত প্রক্রিয়া করা যায়।
- Compound Index সাধারণত তখন ব্যবহৃত হয় যখন আপনার কুয়েরি একাধিক ফিল্ডে নির্দিষ্ট মানে ফিল্টার করছে।
- Compound Index তৈরি করলে MongoDB সেই ইনডেক্স ব্যবহার করে ফিল্টারিং এবং সোর্টিং দুটোই দ্রুত করতে পারে।

### উদাহরণ: Compound Index তৈরি করা
এখানে আমরা `name` এবং `email` ফিল্ডের জন্য একটি Compound Index তৈরি করছি।

```js
UserSchema.index({ name: 1, email: 1 });  // Compound Index on name and email
```

### উদাহরণ: Compound Index ব্যবহার করে কুয়েরি করা
যদি আমরা `name` এবং `email` দুটো ফিল্ডের উপর কুয়েরি করি, তাহলে MongoDB Compound Index ব্যবহার করবে।

```js
const user = await User.find({ name: 'John', email: 'john@example.com' });
```

**Compound Index** ব্যবহার করে MongoDB একটি ইনডেক্স স্ক্যান করবে, যেখানে এটি দুটি ফিল্ডের মান ব্যবহার করে দ্রুত ফলাফল ফিরিয়ে দেবে।

## 🟢 Text Index
**Text Index** হল একটি বিশেষ ধরনের ইনডেক্স যা MongoDB তে টেক্সট ডেটার উপর অনুসন্ধান পরিচালনা করতে ব্যবহৃত হয়। এটি MongoDB কে দ্রুত টেক্সটের মধ্যে শব্দ অনুসন্ধান করতে সাহায্য করে। Text Index সাধারণত বড় পরিমাণের টেক্সট ডেটা যেখানে শব্দ বা বাক্যের মধ্যে অনুসন্ধান করা হয়, সেখানে ব্যবহৃত হয়।

- **Text Index** স্বয়ংক্রিয়ভাবে সব শব্দকে ইনডেক্স করে, এবং আপনি MongoDB-তে বিভিন্ন কুয়েরি (যেমন: `$text`) ব্যবহার করে টেক্সটের মধ্যে দ্রুত অনুসন্ধান করতে পারবেন।
- MongoDB একটি ডকুমেন্টে একাধিক **Text Index** তৈরি করতে পারে এবং আপনি কুয়েরি করতে পারেন যে কোনও ভাষায়।
- Text Index ব্যবহার করলে MongoDB ফিল্টারিং, সোর্টিং, এবং ফাজি অনুসন্ধান দ্রুত করতে পারে।

### উদাহরণ: Text Index তৈরি করা
এখানে আমরা `description` ফিল্ডের জন্য একটি Text Index তৈরি করছি।

```js
ProductSchema.index({ description: 'text' });  // Text Index on description
```

### উদাহরণ: Text Index ব্যবহার করে কুয়েরি করা
যদি আমরা `description` ফিল্ডের মধ্যে টেক্সট অনুসন্ধান করতে চাই, তাহলে MongoDB **$text** অপারেটর ব্যবহার করবে।

```js
const products = await Product.find({ $text: { $search: 'laptop' } });
```

এখানে MongoDB **Text Index** ব্যবহার করে `description` ফিল্ডে "laptop" শব্দটি খুঁজে বের করবে এবং সমস্ত ডকুমেন্ট রিটার্ন করবে যেগুলোর মধ্যে এই শব্দটি রয়েছে।

## 🏁 সার্ভার চালানো:
```js
app.listen(5000, () => {
  console.log('Server is running on port 5000');
});
```

---
🔥 **Compound Index** একাধিক ফিল্ডের উপর ইনডেক্স তৈরি করতে ব্যবহৃত হয় এবং এটি এমন কুয়েরি দ্রুত করতে সহায়তা করে যেগুলো একাধিক ফিল্ডে নির্ভরশীল।
🔥 **Text Index** টেক্সট ডেটার উপর অনুসন্ধান করতে ব্যবহৃত হয়, বিশেষ করে যখন বড় পরিমাণের টেক্সট ডেটাতে শব্দ বা বাক্যের মধ্যে দ্রুত অনুসন্ধান করা প্রয়োজন।



