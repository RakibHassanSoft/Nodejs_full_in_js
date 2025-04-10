# Day 43

✅ **আজকের দিনটি: Advanced queries (`$gt`, `$in`, `$regex`, etc.)**

আজকের দিনে আমরা MongoDB এর **advanced queries** শিখবো, যেগুলি আমাদের **Express.js** অ্যাপ্লিকেশনে **filtering** এবং **searching** এর জন্য খুবই সহায়ক হবে। বিশেষ করে, আমরা শিখবো কিভাবে MongoDB এর `$gt`, `$in`, `$regex`, এবং অন্যান্য অপারেটর ব্যবহার করা যায়।

---

## ⏸️ 1. MongoDB Advanced Queries

MongoDB এর কিছু বিশেষ **query operators** আছে যেগুলি আমাদের ডেটা ফিল্টারিং বা সিলেকশনে আরো বেশি flexibility দেয়। এগুলি হল:

- **$gt**: Greater than (বড়)
- **$lt**: Less than (ছোট)
- **$in**: Match any value in the provided array
- **$regex**: Match using regular expressions

এগুলো আমাদের ডেটাবেসে খুব নির্দিষ্ট তথ্য খুঁজে বের করার জন্য ব্যবহার করা হয়।

---

## ⏸️ 2. Setting Up Express and MongoDB Connection

প্রথমে, আমাদের **Express** এবং **MongoDB** সংযোগ স্থাপন করতে হবে।

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

// MongoDB connection
mongoose.connect('mongodb://localhost:27017/advancedQueries', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Schema and Model
const Product = mongoose.model('Product', new mongoose.Schema({
  name: String,
  price: Number,
  category: String,
  description: String,
}));

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- আমরা MongoDB এর সাথে সংযোগ করেছি এবং **Product** মডেল তৈরি করেছি।

---

## ⏸️ 3. Using `$gt`, `$in`, and `$regex` Queries

এখন, আমরা MongoDB এর কিছু অ্যাডভান্সড কুয়েরি অপারেটর ব্যবহার করে ডেটা ফিল্টারিং করব।

### Example 1: `$gt` (Greater than)

```js
app.get('/products/expensive', async (req, res) => {
  try {
    const products = await Product.find({ price: { $gt: 100 } }); // price > 100
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- `$gt: 100` দিয়ে **price** এর মান ১০০ এর বেশি এমন প্রোডাক্টগুলি পাওয়া যাবে।

### Example 2: `$in` (Match any value from an array)

```js
app.get('/products/category', async (req, res) => {
  try {
    const categories = ['Electronics', 'Furniture'];
    const products = await Product.find({ category: { $in: categories } }); // category in Electronics or Furniture
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- `$in: ['Electronics', 'Furniture']` দিয়ে প্রোডাক্টের **category** যেগুলি Electronics অথবা Furniture, সেই প্রোডাক্টগুলি পাওয়া যাবে।

### Example 3: `$regex` (Pattern matching)

```js
app.get('/products/search', async (req, res) => {
  try {
    const keyword = req.query.keyword || '';
    const products = await Product.find({ description: { $regex: keyword, $options: 'i' } }); // Case-insensitive search
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- `$regex` দিয়ে **description** ফিল্ডে ইনপুট করা কিওয়ার্ডের সাথে মেলে এমন প্রোডাক্টগুলিকে পাওয়া যাবে।
- `i` অপশন ব্যবহার করা হয়েছে যাতে কেস ইনসেনসিটিভ সার্চ হয়।

---

## ⏸️ 4. Testing the Routes

এখন, আমরা আমাদের তৈরি করা রাউটগুলোকে **Postman** বা **curl** ব্যবহার করে টেস্ট করতে পারি।

### Testing `/products/expensive` Route

```bash
curl -X GET http://localhost:3000/products/expensive
```

এখানে:
- আমরা **price > 100** এর মতো প্রোডাক্টের তথ্য চাইছি।

### Testing `/products/category` Route

```bash
curl -X GET http://localhost:3000/products/category?categories=Electronics,Furniture
```

এখানে:
- আমরা **Electronics** অথবা **Furniture** ক্যাটেগরির প্রোডাক্ট চাইছি।

### Testing `/products/search` Route

```bash
curl -X GET "http://localhost:3000/products/search?keyword=phone"
```

এখানে:
- আমরা **description** ফিল্ডে "phone" শব্দটি থাকা প্রোডাক্টগুলো খুঁজে বের করতে চাই।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **MongoDB advanced queries** যেমন `$gt`, `$in`, `$regex` ইত্যাদি ব্যবহার করা।
- **Express.js** অ্যাপ্লিকেশন ব্যবহার করে MongoDB এর সাথে এডভান্সড কুয়েরি অপারেটরগুলি প্রয়োগ করা।
- **filtering** এবং **searching** করার জন্য MongoDB এর কুয়েরি অপারেটরগুলো কিভাবে ব্যবহার করা যায়।

আজকের দিনে আপনি শিখলেন কিভাবে MongoDB এর বিভিন্ন অ্যাডভান্সড কুয়েরি অপারেটর ব্যবহার করে ডেটা ফিল্টার করা যায় এবং **Express.js** এর মাধ্যমে তা ইমপ্লিমেন্ট করা। 🛠️🚀






# Day 44

✅ **আজকের দিনটি: Pagination: `.skip()`, `.limit()`**

আজকের দিনে আমরা MongoDB তে **pagination** প্রয়োগ করবো, যা আমাদের ডেটাবেস থেকে বড় ডেটা সেটগুলোকে ছোট ছোট অংশে ভাগ করতে সাহায্য করবে। এর জন্য আমরা MongoDB এর `.skip()` এবং `.limit()` মেথড ব্যবহার করবো। এই দুটি মেথডের মাধ্যমে আমরা নির্দিষ্ট সংখ্যক ডেটা ফেচ করতে পারব এবং **next** বা **previous** পেজ এর জন্যও কোডিং করতে পারব।

---

## ⏸️ 1. Pagination: `.skip()` and `.limit()`

MongoDB তে **pagination** করা অনেক গুরুত্বপূর্ণ যখন আপনার কাছে বড় ডেটাবেস থাকে এবং আপনি ডেটার একটি অংশ দেখাতে চান।

- **`.skip()`**: এটি নির্দিষ্ট সংখ্যক ডকুমেন্ট স্কিপ করে দেয়। এটি মূলত পেজিনেশনের জন্য ব্যবহৃত হয় যাতে আপনি কোন পেজে রয়েছেন তা নির্ধারণ করতে পারেন।
- **`.limit()`**: এটি কতগুলি ডকুমেন্ট আপনি পেতে চান তা নির্ধারণ করে। উদাহরণস্বরূপ, আপনি যদি এক পেজে ১০টি ডকুমেন্ট দেখতে চান, তবে এটি ব্যবহার করবেন।

---

## ⏸️ 2. Express.js Setup with MongoDB

প্রথমে, আমাদের **Express.js** এবং **MongoDB** সেটআপ করতে হবে।

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

// MongoDB connection
mongoose.connect('mongodb://localhost:27017/paginationDemo', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Schema and Model
const Product = mongoose.model('Product', new mongoose.Schema({
  name: String,
  price: Number,
  category: String,
  description: String,
}));

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- আমরা **MongoDB** এর সাথে সংযোগ করেছি এবং **Product** মডেল তৈরি করেছি।

---

## ⏸️ 3. Implementing Pagination with `.skip()` and `.limit()`

এখন, আমরা **pagination** প্রয়োগ করব। এই উদাহরণে, আমাদের **Product** মডেল ব্যবহার করে, এক পেজে ১০টি প্রোডাক্ট দেখাবো এবং **skip** এবং **limit** দিয়ে পেজের ডেটা লোড করবো।

```js
app.get('/products', async (req, res) => {
  try {
    const page = parseInt(req.query.page) || 1; // Page number from query parameter (default to 1)
    const limit = parseInt(req.query.limit) || 10; // Number of products per page (default to 10)
    const skip = (page - 1) * limit; // Calculate how many items to skip

    const products = await Product.find()
      .skip(skip)  // Skip the documents based on page
      .limit(limit);  // Limit the number of documents per page

    const totalProducts = await Product.countDocuments(); // Get the total count of products

    res.json({
      totalProducts,
      totalPages: Math.ceil(totalProducts / limit), // Calculate total number of pages
      currentPage: page,
      products,
    });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা `page` এবং `limit` কোয়েরি প্যারামিটার থেকে পেয়েছি।
- **`.skip()`** মেথড দিয়ে আমরা পেজের জন্য প্রোডাক্ট ডেটা ফিল্টার করেছি এবং **`.limit()`** মেথড দিয়ে প্রতিটি পেজে কতগুলি ডকুমেন্ট দেখাতে চাই তা নির্ধারণ করেছি।
- আমরা `totalProducts` হিসেব করে **totalPages** নির্ধারণ করেছি, যাতে ফ্রন্টএন্ডে পেজিনেশন ব্যবহারকারীকে সঠিক তথ্য দেখানো যায়।

---

## ⏸️ 4. Testing the Pagination Route

এখন, আপনি **Postman** অথবা **curl** ব্যবহার করে **pagination** রাউটটি টেস্ট করতে পারবেন।

### Testing `/products` Route with Pagination

```bash
curl -X GET "http://localhost:3000/products?page=2&limit=10"
```

এখানে:
- আমরা **page** প্যারামিটার হিসেবে `2` দিয়েছি, অর্থাৎ দ্বিতীয় পেজের ডেটা দেখতে চাই।
- আমরা **limit** প্যারামিটার হিসেবে `10` দিয়েছি, অর্থাৎ এক পেজে ১০টি প্রোডাক্ট দেখাবো।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- MongoDB তে **pagination** করা কিভাবে `.skip()` এবং `.limit()` ব্যবহার করে।
- **Express.js** রাউট তৈরি করে pagination ফিচার ইমপ্লিমেন্ট করা।
- কিভাবে একটি পেজে নির্দিষ্ট সংখ্যক ডেটা দেখানো যায় এবং পরবর্তী পেজে যেতে স্কিপিং এবং লিমিটিং করা হয়।

আজকের দিনে আপনি শিখলেন কিভাবে MongoDB তে pagination তৈরি করা যায় এবং **Express.js** এর সাথে এটি প্রয়োগ করা যায়। 🛠️🚀






# Day 45

✅ **আজকের দিনটি: Aggregation: `$match`, `$group`, `$lookup`, `$project`**

আজকের দিনে আমরা **MongoDB Aggregation** নিয়ে কাজ করবো। Aggregation হল MongoDB এর একটি শক্তিশালী টুল যা ডেটা প্রসেসিং এবং বিশ্লেষণের জন্য ব্যবহৃত হয়। আমরা বিভিন্ন Aggregation অপারেটরগুলি শিখবো যেমন: `$match`, `$group`, `$lookup`, এবং `$project`।

---

## ⏸️ 1. MongoDB Aggregation Overview

**Aggregation** হল MongoDB এর একটি প্রক্রিয়া যেখানে ডেটাকে বিভিন্ন ধাপে প্রক্রিয়া করা হয়। এটি সাধারণত **data transformation** বা **data analysis** এর জন্য ব্যবহৃত হয়। MongoDB তে Aggregation পাইপলাইন ব্যবহার করে ডেটা প্রক্রিয়া করা হয়।

- **`$match`**: এটি ডেটার মধ্যে ফিল্টার করার জন্য ব্যবহার হয়, যেমন SQL এর `WHERE` ক্লজ।
- **`$group`**: এটি ডেটাকে গ্রুপিং করার জন্য ব্যবহৃত হয়, যেমন SQL এর `GROUP BY` ক্লজ।
- **`$lookup`**: এটি দুটি কলোবরেটিং কলেকশনের মধ্যে join করার জন্য ব্যবহৃত হয়।
- **`$project`**: এটি ডেটার কিছু ফিল্ড চয়ন করে, অথবা নতুন ফিল্ড তৈরি করে।

---

## ⏸️ 2. Aggregation Pipeline Setup in Express.js

প্রথমে, আমাদের **Express.js** এবং **MongoDB Aggregation** সেটআপ করতে হবে। এর জন্য আমরা **Product** মডেল ব্যবহার করবো এবং আমরা আজকে কয়েকটি aggregation অপারেটর প্রয়োগ করবো।

### Express.js Setup

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

// MongoDB connection
mongoose.connect('mongodb://localhost:27017/aggregationDemo', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Schema and Model
const Product = mongoose.model('Product', new mongoose.Schema({
  name: String,
  price: Number,
  category: String,
  description: String,
}));

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- আমরা **MongoDB** এর সাথে সংযোগ করেছি এবং **Product** মডেল তৈরি করেছি।

---

## ⏸️ 3. Using Aggregation Operators

এখন, আমরা বিভিন্ন aggregation অপারেটর প্রয়োগ করবো। নিচে **$match**, **$group**, **$lookup**, এবং **$project** এর উদাহরণ দেওয়া হলো:

### **$match** Example:

```js
app.get('/products/filter', async (req, res) => {
  try {
    const products = await Product.aggregate([
      { $match: { category: 'Electronics' } }
    ]);
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **`$match`** ব্যবহার করে **category** ফিল্টার করেছি, যাতে শুধুমাত্র **Electronics** ক্যাটেগরির প্রোডাক্টগুলো পাওয়া যায়।

---

### **$group** Example:

```js
app.get('/products/group', async (req, res) => {
  try {
    const products = await Product.aggregate([
      { $group: { _id: "$category", totalPrice: { $sum: "$price" } } }
    ]);
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **`$group`** অপারেটর ব্যবহার করে **category** অনুযায়ী গ্রুপিং করেছি এবং সেই গ্রুপের মধ্যে **price** এর মোট যোগফল বের করেছি।

---

### **$lookup** Example (Join Two Collections):

```js
const Order = mongoose.model('Order', new mongoose.Schema({
  productId: mongoose.Schema.Types.ObjectId,
  quantity: Number
}));

app.get('/orders/lookup', async (req, res) => {
  try {
    const orders = await Order.aggregate([
      {
        $lookup: {
          from: 'products',          // Join with the 'products' collection
          localField: 'productId',   // Field from 'orders' collection
          foreignField: '_id',       // Field from 'products' collection
          as: 'productDetails'       // The field to store joined data
        }
      }
    ]);
    res.json(orders);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **`$lookup`** অপারেটর ব্যবহার করে দুটি collection (`orders` এবং `products`) এর মধ্যে join করেছি।

---

### **$project** Example:

```js
app.get('/products/project', async (req, res) => {
  try {
    const products = await Product.aggregate([
      { $project: { name: 1, price: 1, _id: 0 } }
    ]);
    res.json(products);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **`$project`** অপারেটর ব্যবহার করে **name** এবং **price** ফিল্ড দেখাচ্ছি, এবং **_id** ফিল্ড বাদ দিচ্ছি।

---

## ⏸️ 4. Testing the Aggregation Routes

এখন, আপনি **Postman** অথবা **curl** ব্যবহার করে **aggregation** রাউটগুলো টেস্ট করতে পারবেন।

### Testing `/products/filter` Route

```bash
curl -X GET "http://localhost:3000/products/filter"
```

এখানে:
- এই রাউটটি **category: 'Electronics'** এর প্রোডাক্টগুলো দেখাবে।

### Testing `/products/group` Route

```bash
curl -X GET "http://localhost:3000/products/group"
```

এখানে:
- এই রাউটটি **category** অনুযায়ী প্রোডাক্টের মোট মূল্য দেখাবে।

### Testing `/orders/lookup` Route

```bash
curl -X GET "http://localhost:3000/orders/lookup"
```

এখানে:
- এই রাউটটি **orders** এবং **products** এর মধ্যে join করা ডেটা দেখাবে।

### Testing `/products/project` Route

```bash
curl -X GET "http://localhost:3000/products/project"
```

এখানে:
- এই রাউটটি **name** এবং **price** ফিল্ডগুলো দেখাবে এবং **_id** বাদ দিয়ে দেখাবে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **MongoDB Aggregation** অপারেটর যেমন: `$match`, `$group`, `$lookup`, এবং `$project`।
- **Aggregation Pipeline** ব্যবহার করে কিভাবে ডেটা প্রসেস করা যায়।
- **Express.js** এর মাধ্যমে **MongoDB Aggregation** প্রয়োগ করার প্র্যাকটিকাল উদাহরণ।

আজকের দিনে আপনি শিখলেন MongoDB তে বিভিন্ন **aggregation** অপারেটর ব্যবহার করা। এটি আপনাকে ডেটা প্রসেসিং এবং বিশ্লেষণের ক্ষেত্রে সাহায্য করবে। 🛠️🚀






# Day 46

✅ **আজকের দিনটি: Join collections using `populate()`**

আজকের দিনে আমরা **Mongoose** এর `populate()` মেথড শিখবো, যা MongoDB তে **collections** এর মধ্যে **join** করতে ব্যবহৃত হয়। `populate()` মেথডটি ব্যবহৃত হয় যখন আমাদের একাধিক কলেকশনের মধ্যে সম্পর্ক তৈরি করতে হয়, যেমন **One-to-many** বা **Many-to-many** সম্পর্ক। এই মেথডের মাধ্যমে আপনি এক কলেকশনের ডেটা থেকে অন্য কলেকশনের ডেটা যুক্ত করতে পারবেন।

---

## ⏸️ 1. `populate()` Overview

**`populate()`** হল Mongoose এর একটি মেথড যা আমাদের **document references** যোগ করতে সাহায্য করে। যখন একটি collection এর একটি field অন্য একটি collection এর **ObjectId** রেফার করে, তখন `populate()` ব্যবহার করে সেই **ObjectId** এর সাথে সম্পর্কিত তথ্য পাওয়া যায়। এটি মূলত **join** অপারেশনের মতো কাজ করে, যা SQL তে বিভিন্ন টেবিলের মধ্যে সম্পর্ক গড়ে তোলে।

---

## ⏸️ 2. Setting up the Example Collections

আজকের উদাহরণে, আমরা একটি **Order** এবং **Product** collection তৈরি করবো, যেখানে **Order** collection এর মধ্যে **Product** এর `ObjectId` থাকবে। আমরা `populate()` ব্যবহার করে **Order** collection এর সাথে **Product** collection এর তথ্য যুক্ত করবো।

### Express.js Setup

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

// MongoDB connection
mongoose.connect('mongodb://localhost:27017/populateDemo', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Define Product Schema and Model
const Product = mongoose.model('Product', new mongoose.Schema({
  name: String,
  price: Number,
  category: String
}));

// Define Order Schema and Model
const Order = mongoose.model('Order', new mongoose.Schema({
  product: { type: mongoose.Schema.Types.ObjectId, ref: 'Product' },
  quantity: Number,
  totalPrice: Number
}));

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- **Product** এবং **Order** মডেল তৈরি করা হয়েছে, যেখানে **Order** মডেলটির **product** ফিল্ডে **Product** এর `ObjectId` রেফারেন্স রয়েছে।

---

## ⏸️ 3. Using `populate()` to Join Collections

এখন, আমরা `populate()` ব্যবহার করে **Order** এর মধ্যে **Product** এর তথ্য যুক্ত করবো।

### `populate()` Example:

```js
app.get('/orders', async (req, res) => {
  try {
    const orders = await Order.find().populate('product');
    res.json(orders);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`Order.find()`** দিয়ে সমস্ত অর্ডার খোঁজা হচ্ছে।
- **`.populate('product')`** ব্যবহার করে আমরা **Order** এর **product** ফিল্ডের সাথে সম্পর্কিত **Product** ডেটা যোগ করছি। এর ফলে প্রতিটি অর্ডারের সাথে সংশ্লিষ্ট প্রোডাক্টের তথ্য পাওয়া যাবে।

---

## ⏸️ 4. Testing the `populate()` Route

এখন, আপনি **Postman** অথবা **curl** ব্যবহার করে এই রাউটটি টেস্ট করতে পারবেন।

### Testing `/orders` Route

```bash
curl -X GET "http://localhost:3000/orders"
```

এখানে:
- এই রাউটটি **Order** collection এর সাথে সম্পর্কিত **Product** collection এর তথ্য পাবে এবং তাদের সম্পর্কিত তথ্য একত্রে দেখাবে।

---

## ⏸️ 5. Working with Nested `populate()`

যদি আপনার **Order** collection এর মধ্যে আরও nested `populate()` ব্যবহার করতে হয়, যেমন **customer** বা **address** ফিল্ড, তাহলে আপনি নিম্নরূপ ব্যবহার করতে পারেন:

```js
app.get('/orders', async (req, res) => {
  try {
    const orders = await Order.find()
      .populate({
        path: 'product',
        select: 'name price category'  // Only select these fields
      });
    res.json(orders);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা `product` ফিল্ডের **name**, **price**, এবং **category** ফিল্ডগুলি নির্বাচন করছি।

---

## ⏸️ 6. Handling `populate()` with Multiple Fields

যদি আপনার একাধিক ফিল্ডের মধ্যে **populate()** প্রয়োগ করতে হয়, তবে আপনি এইভাবে করতে পারেন:

```js
app.get('/orders', async (req, res) => {
  try {
    const orders = await Order.find()
      .populate('product')   // Populate product
      .populate('customer'); // Populate customer
    res.json(orders);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা একই রাউটে **`product`** এবং **`customer`** ফিল্ড দুটি **populate()** করেছি।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Mongoose populate()** মেথড ব্যবহারের মাধ্যমে একাধিক collections এর মধ্যে **join** করা।
- **populate()** এর মাধ্যমে কিভাবে **ObjectId** রেফারেন্স এর তথ্য যুক্ত করা যায়।
- **nested populate()** এবং **multiple populate()** প্রয়োগের মাধ্যমে আরও কার্যকরী ডেটা ফেচিং করা।

আজকের দিনে আপনি শিখলেন **`populate()`** এর মাধ্যমে কিভাবে collections এর মধ্যে সম্পর্ক গড়ে তুলে ডেটা একত্রিত করতে হয়। এটি আপনাকে আরও কার্যকরীভাবে ডেটাবেস মডেল তৈরি এবং ম্যানেজ করার ক্ষেত্রে সাহায্য করবে। 🛠️🚀





# Day 47

✅ **আজকের দিনটি: Partial Update: Primitive & Non-Primitive types**

আজকের দিনে আমরা **MongoDB** তে **Partial Update** সম্পর্কে শিখবো। **Partial Update** এর মাধ্যমে আপনি ডেটাবেসের কোন একটি অংশ বা নির্দিষ্ট ফিল্ড আপডেট করতে পারেন, যেমন **Primitive** এবং **Non-Primitive** types।

---

## ⏸️ 1. Partial Update Overview

**Partial Update** এর মাধ্যমে আপনি সম্পূর্ণ ডকুমেন্ট না পরিবর্তন করে কেবলমাত্র কিছু নির্দিষ্ট ফিল্ড পরিবর্তন করতে পারবেন। MongoDB তে এই ধরনের আপডেট **`updateOne()`**, **`updateMany()`**, অথবা **`findOneAndUpdate()`** মেথডের মাধ্যমে করা যায়।

---

## ⏸️ 2. Primitive Types Update

**Primitive Types** এর মধ্যে **String**, **Number**, **Boolean** ইত্যাদি ফিল্ড থাকে। এসব ফিল্ড আপডেট করা অনেক সহজ। আমরা **Mongoose** এর **`updateOne()`** মেথড ব্যবহার করে একটি primitive type ফিল্ডকে আপডেট করবো।

### Example: Update a Primitive Type (String)

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

mongoose.connect('mongodb://localhost:27017/partialUpdateDemo', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Define User Schema and Model
const User = mongoose.model('User', new mongoose.Schema({
  name: String,
  age: Number,
  email: String
}));

// Endpoint for updating user's name (Primitive Type)
app.patch('/user/:id', async (req, res) => {
  try {
    const user = await User.updateOne(
      { _id: req.params.id },
      { $set: { name: req.body.name } }
    );
    res.json(user);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- আমরা **User** মডেলের **name** ফিল্ডটিকে **`updateOne()`** মেথড দিয়ে আপডেট করেছি। এটি কেবল **name** ফিল্ড আপডেট করবে, বাকী ফিল্ডগুলো অপরিবর্তিত থাকবে।

---

## ⏸️ 3. Non-Primitive Types Update

**Non-Primitive Types** এর মধ্যে **Array**, **Object**, এবং **Subdocuments** ইত্যাদি অন্তর্ভুক্ত থাকে। এগুলোর ক্ষেত্রে **partial update** করতে কিছু অতিরিক্ত কাজ প্রয়োজন হতে পারে।

### Example: Update Non-Primitive Type (Array)

```js
// Define Product Schema with Array type
const Product = mongoose.model('Product', new mongoose.Schema({
  name: String,
  categories: [String]  // Array of categories
}));

// Endpoint for updating product categories (Non-Primitive Type)
app.patch('/product/:id', async (req, res) => {
  try {
    const product = await Product.updateOne(
      { _id: req.params.id },
      { $push: { categories: req.body.category } }  // Add new category to array
    );
    res.json(product);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **Product** মডেলের **categories** অ্যারে ফিল্ডে নতুন একটি ক্যাটেগরি যোগ করেছি। **$push** অপারেটর ব্যবহার করে নতুন ডাটা অ্যারেতে যোগ করা হয়েছে।

---

## ⏸️ 4. Update Subdocument (Non-Primitive Type)

এখন আমরা দেখবো কিভাবে একটি **Subdocument** আপডেট করা যায়। যদি আপনার কোন মডেলে **subdocument** থাকে, তাহলে আপনি সেই subdocument এর কিছু ফিল্ড আপডেট করতে পারবেন।

### Example: Update Subdocument Field

```js
// Define Order Schema with Subdocument (Product)
const Order = mongoose.model('Order', new mongoose.Schema({
  orderNumber: String,
  products: [{
    name: String,
    price: Number
  }]
}));

// Endpoint for updating product price (Subdocument)
app.patch('/order/:id', async (req, res) => {
  try {
    const order = await Order.updateOne(
      { _id: req.params.id, 'products._id': req.body.productId },
      { $set: { 'products.$.price': req.body.price } }  // Update price of specific product
    );
    res.json(order);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- আমরা **Order** মডেলের মধ্যে **products** নামক একটি **subdocument array** ব্যবহার করেছি।
- **`products.$.price`** এর মাধ্যমে আমরা অ্যারের মধ্যে নির্দিষ্ট প্রোডাক্টের **price** আপডেট করেছি।

---

## ⏸️ 5. Using `$set` for Partial Updates

**Partial Update** করার সময় সাধারণত **`$set`** অপারেটর ব্যবহার করা হয়, যা কেবলমাত্র নির্দিষ্ট ফিল্ড বা ডেটা পরিবর্তন করে।

### Example: Update Specific Field Using `$set`

```js
app.patch('/user/email/:id', async (req, res) => {
  try {
    const updatedUser = await User.updateOne(
      { _id: req.params.id },
      { $set: { email: req.body.email } }
    );
    res.json(updatedUser);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`$set`** অপারেটর ব্যবহার করে শুধুমাত্র **email** ফিল্ড আপডেট করা হয়েছে। 

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Partial Update** এর মাধ্যমে নির্দিষ্ট ফিল্ড বা ডেটা পরিবর্তন করা।
- **Primitive** এবং **Non-Primitive** types এর জন্য আলাদা আপডেট কৌশল।
- **`$set`**, **`$push`**, এবং **subdocument updates** এর মাধ্যমে MongoDB ডেটা আপডেট করা।
- **Mongoose** এবং **Express.js** এর মাধ্যমে ফিল্ড ভিত্তিক আপডেট কিভাবে করতে হয়।

আজকের দিনে আপনি শিখলেন কিভাবে MongoDB তে **Partial Update** করতে হয় এবং Primitive & Non-Primitive types এর ক্ষেত্রে বিভিন্ন কৌশল প্রয়োগ করা হয়। 🛠️🚀





# Day 48

✅ **আজকের দিনটি: Use `findByIdAndUpdate` with options**

আজকের দিনে আমরা **MongoDB** তে **`findByIdAndUpdate`** মেথড ব্যবহার করবো এবং বিভিন্ন **options** এর মাধ্যমে ডেটা আপডেট করার পদ্ধতি শিখবো।

---

## ⏸️ 1. `findByIdAndUpdate` Overview

**`findByIdAndUpdate`** মেথডটি একটি ডকুমেন্টের আইডি ব্যবহার করে MongoDB তে ডেটা আপডেট করতে ব্যবহৃত হয়। এই মেথডটি দুটি গুরুত্বপূর্ণ সুবিধা প্রদান করে:
1. এটি ডকুমেন্টের একটি নির্দিষ্ট **ID** এর মাধ্যমে আপডেট করতে সাহায্য করে।
2. এটি **options** প্যারামিটার ব্যবহার করে আপনি কিভাবে আপডেট হওয়া ডেটা ফেরত পাবেন তা কাস্টমাইজ করতে পারেন।

এছাড়াও, এই মেথডটি **`updateOne`** এর মত কাজ করে, তবে এটি ডকুমেন্টটি ফেরত দেয়।

---

## ⏸️ 2. Basic Usage of `findByIdAndUpdate`

এটি একটি সাধারণ ব্যবহার যেখানে একটি ডকুমেন্ট আপডেট করা হয় আইডি ব্যবহার করে এবং শুধুমাত্র নতুন ডেটা ফেরত আসে।

### Example: Basic `findByIdAndUpdate` Usage

```js
const express = require('express');
const mongoose = require('mongoose');
const app = express();
const port = 3000;

mongoose.connect('mongodb://localhost:27017/findByIdAndUpdateDemo', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Define User Schema and Model
const User = mongoose.model('User', new mongoose.Schema({
  name: String,
  age: Number,
  email: String
}));

// Endpoint for updating user's name using findByIdAndUpdate
app.patch('/user/:id', async (req, res) => {
  try {
    const updatedUser = await User.findByIdAndUpdate(
      req.params.id,         // User's ID
      { name: req.body.name },  // Data to update
      { new: true }           // Return the updated document
    );
    res.json(updatedUser);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- **`findByIdAndUpdate`** ব্যবহার করে একটি ইউজারের **name** ফিল্ড আপডেট করা হয়েছে।
- **`new: true`** option ব্যবহার করা হয়েছে যাতে আপডেট হওয়া ডেটা ফেরত পাওয়া যায়।

---

## ⏸️ 3. Options with `findByIdAndUpdate`

**`findByIdAndUpdate`** মেথডটি বিভিন্ন **options** গ্রহণ করে যা কাস্টমাইজেশন করতে সাহায্য করে। নিচে কিছু সাধারণ **options** রয়েছে যা আপনি ব্যবহার করতে পারেন:

### Common Options:
- **`new`**: এই অপশনটি যদি `true` হয়, তাহলে আপডেট হওয়া ডকুমেন্টটি ফেরত আসবে। ডিফল্ট হিসেবে এটি `false` থাকে, যার মানে পুরনো ডেটা ফেরত আসে।
- **`runValidators`**: এই অপশনটি যদি `true` হয়, তাহলে আপডেটের সময় **validation** চলবে। ডিফল্টভাবে এটি `false` থাকে।
- **`context`**: এই অপশনটি আপনি `validation` মেথডের কনটেক্সট সেট করতে ব্যবহার করতে পারেন।

### Example: Using Multiple Options

```js
app.patch('/user/:id', async (req, res) => {
  try {
    const updatedUser = await User.findByIdAndUpdate(
      req.params.id,         // User's ID
      { age: req.body.age },  // Data to update
      {
        new: true,            // Return updated document
        runValidators: true,  // Run validation during update
        context: 'query'      // Set context for validation
      }
    );
    res.json(updatedUser);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`new: true`** ব্যবহার করে আপডেট হওয়া ডেটা ফেরত পাওয়া যাবে।
- **`runValidators: true`** ব্যবহার করলে **validation** চালু হবে, যার মাধ্যমে যদি **age** ফিল্ডটি একটি **positive integer** না হয়, তবে তা আপডেট হবে না।

---

## ⏸️ 4. Update Nested Fields with `findByIdAndUpdate`

আপনি যদি **nested fields** বা **subdocuments** আপডেট করতে চান, তবে আপনি সহজেই **dot notation** ব্যবহার করে নির্দিষ্ট ফিল্ড আপডেট করতে পারবেন।

### Example: Update Nested Field

```js
// Define Order Schema with Subdocument (Product)
const Order = mongoose.model('Order', new mongoose.Schema({
  orderNumber: String,
  products: [{
    name: String,
    price: Number
  }]
}));

// Endpoint for updating price of specific product in nested array
app.patch('/order/:id', async (req, res) => {
  try {
    const updatedOrder = await Order.findByIdAndUpdate(
      req.params.id,                         // Order's ID
      { 'products.$.price': req.body.price }, // Update specific product's price
      { new: true }                           // Return the updated document
    );
    res.json(updatedOrder);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`'products.$.price'`** এর মাধ্যমে **products** অ্যারের মধ্যে **specific product's price** আপডেট করা হয়েছে।

---

## ⏸️ 5. Using `findByIdAndUpdate` for Atomic Updates

**`findByIdAndUpdate`** মেথডটি MongoDB তে **atomic** আপডেট সমর্থন করে। অর্থাৎ, একাধিক অ্যাটমিক অপারেশন একযোগে করা যায়।

### Example: Atomic Update with `$inc` Operator

```js
app.patch('/user/increment-age/:id', async (req, res) => {
  try {
    const updatedUser = await User.findByIdAndUpdate(
      req.params.id,
      { $inc: { age: 1 } },  // Increment age by 1
      { new: true }           // Return updated document
    );
    res.json(updatedUser);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`$inc`** অপারেটর ব্যবহার করে **age** ফিল্ডের মান ১ বাড়ানো হয়েছে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **`findByIdAndUpdate`** মেথডের মাধ্যমে ডকুমেন্ট আপডেট করা।
- বিভিন্ন **options** ব্যবহার যেমন **`new`**, **`runValidators`**, **`context`** ইত্যাদি।
- **nested fields** বা **subdocuments** আপডেট করার কৌশল।
- **atomic operations** এর মাধ্যমে একাধিক ডেটা আপডেট করা।

আজকের দিনে আপনি শিখলেন কিভাবে **`findByIdAndUpdate`** মেথড ব্যবহার করে MongoDB তে ডেটা আপডেট করা যায় এবং বিভিন্ন **options** প্রয়োগ করা হয়। 🛠️🚀





# Day 49

✅ **আজকের দিনটি: Mini-project: Blog API with author-populated posts**

আজকের দিনে আমরা একটি **Blog API** তৈরি করবো, যেখানে **author-populated posts** থাকবে। এই প্রকল্পে, একটি ব্লগ পোষ্ট তৈরি করার সময় আমরা পোষ্টের সাথে সংশ্লিষ্ট লেখক (author) তথ্যও পাবো।

---

## ⏸️ 1. Set up Mongoose Models for Blog and Author

প্রথমে, আমাদের **Author** এবং **Blog** মডেল তৈরি করতে হবে। **Author** মডেলটি একজন লেখকের তথ্য ধারণ করবে এবং **Blog** মডেলটি ব্লগ পোষ্টের বিস্তারিত সংরক্ষণ করবে।

### Example: Author Model

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
  },
  bio: String
});

const Author = mongoose.model('Author', authorSchema);
module.exports = Author;
```

এখানে:
- **Author** মডেলটি লেখকের নাম, ইমেইল এবং জীবনী সংরক্ষণ করে।

### Example: Blog Model with Author Reference

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
- **Blog** মডেলটি ব্লগ পোষ্টের শিরোনাম, কনটেন্ট এবং লেখককে ধারণ করে।
- **author** ফিল্ডটি **`ObjectId`** হিসেবে **Author** মডেলকে রেফারেন্স করে, যার মাধ্যমে আমরা ব্লগ পোষ্টের সাথে লেখক সম্পর্কিত তথ্য পাবো।

---

## ⏸️ 2. Create API to Add Blog with Author

এখন আমাদের একটি API তৈরি করতে হবে যেটি নতুন ব্লগ পোষ্ট তৈরি করবে এবং লেখক সম্পর্কিত তথ্যও অন্তর্ভুক্ত করবে।

### Example: API to Add Blog with Author

```js
const express = require('express');
const mongoose = require('mongoose');
const Blog = require('./models/Blog');
const Author = require('./models/Author');
const app = express();
const port = 3000;

mongoose.connect('mongodb://localhost:27017/blogAPI', { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log(err));

app.use(express.json());

// Endpoint to add a blog post with an author
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
- **POST `/blogs`** API এর মাধ্যমে নতুন ব্লগ পোষ্ট তৈরি করা হয়েছে।
- ব্লগ পোষ্টের জন্য লেখক (author) এর আইডি **authorId** ফরম থেকে গ্রহণ করা হয় এবং তা **Blog** মডেলে রেফারেন্স হিসেবে ব্যবহার করা হয়।

---

## ⏸️ 3. API to Get Blog with Author Details

এখন, ব্লগ পোষ্ট এবং সংশ্লিষ্ট লেখক তথ্য একত্রে প্রদর্শন করতে একটি API তৈরি করা হবে।

### Example: API to Get Blog with Author Details

```js
// Endpoint to get blog post with populated author details
app.get('/blogs/:id', async (req, res) => {
  try {
    const blog = await Blog.findById(req.params.id).populate('author'); // Populate author details
    if (!blog) {
      return res.status(404).json({ message: 'Blog post not found' });
    }
    res.json(blog);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
```

এখানে:
- **`populate('author')`** ব্যবহার করে, ব্লগ পোষ্টের লেখক (author) এর ডিটেইলস (যেমন নাম, ইমেইল) ব্লগ পোষ্টের সাথে একত্রে ফেরত আসবে।

---

## ⏸️ 4. Testing the Blog API

এখন, আমাদের তৈরি API গুলি পরীক্ষা করা যাবে। **Postman** বা **Insomnia** এর মতো টুল ব্যবহার করে আপনি নিম্নলিখিত রিকোয়েস্টগুলো পাঠাতে পারেন:

1. **POST `/blogs`** রিকোয়েস্ট পাঠান একটি নতুন ব্লগ পোষ্ট তৈরি করতে:
   - **Request Body:**
     ```json
     {
       "title": "My First Blog Post",
       "content": "This is the content of the first blog post.",
       "authorId": "authorObjectIdHere"
     }
     ```
   
2. **GET `/blogs/:id`** রিকোয়েস্ট পাঠান ব্লগ পোষ্ট এবং লেখক তথ্য পেতে:
   - **Response:**
     ```json
     {
       "title": "My First Blog Post",
       "content": "This is the content of the first blog post.",
       "author": {
         "_id": "authorObjectIdHere",
         "name": "Author Name",
         "email": "author@example.com",
         "bio": "Author bio goes here"
       }
     }
     ```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- কিভাবে একটি ব্লগ API তৈরি করতে হয় যা লেখক তথ্য সহ ব্লগ পোষ্ট তৈরি করে।
- **Mongoose** এর **`populate()`** মেথড ব্যবহার করে রেফারেন্স ডেটা (যেমন লেখক তথ্য) ব্লগ পোষ্টের সাথে একত্রে ফেরত পাওয়া যায়।
- ব্লগ API গুলিকে **Postman** অথবা **Insomnia** দিয়ে পরীক্ষা করা।

আজকের দিনে আপনি শিখলেন কিভাবে ব্লগ পোষ্ট এবং লেখক সম্পর্কিত তথ্য সংরক্ষণ এবং ফেরত দিতে হবে। 🎉🚀





