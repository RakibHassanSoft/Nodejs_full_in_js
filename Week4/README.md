# Day 22

✅ **আজকের দিনটি MongoDB সেটআপ এবং MongoDB Atlas-এর সাথে কানেকশন নিয়ে।**  
আজকের লক্ষ্য হচ্ছে MongoDB ডাটাবেস সেটআপ করা এবং MongoDB Atlas এর সাথে কানেক্ট করা। MongoDB Atlas হলো একটি ক্লাউড-ভিত্তিক MongoDB সার্ভিস যা আমাদের MongoDB ডাটাবেসকে অনলাইনে পরিচালনা করতে সহায়ক হবে। 

---

## ⏸️ 1. MongoDB Atlas এ অ্যাকাউন্ট তৈরি করুন

প্রথমে, [MongoDB Atlas](https://www.mongodb.com/cloud/atlas) ওয়েবসাইটে গিয়ে একটি অ্যাকাউন্ট তৈরি করুন। যদি আপনার ইতিমধ্যে অ্যাকাউন্ট থাকে, তাহলে সাইন ইন করুন।

---

## ⏸️ 2. নতুন ক্লাস্টার তৈরি করুন

1. **Login** করার পর, ড্যাশবোর্ডে যান।
2. `Build a Cluster` এ ক্লিক করুন।
3. একটি ফ্রি প্ল্যান (Free Tier) নির্বাচন করুন এবং `Cluster` তৈরি করতে ডিফল্ট সেটিংস ব্যবহার করুন।
4. প্রোফাইল তৈরি করুন এবং ক্লাস্টার তৈরি শেষ হলে, কিছু সময় অপেক্ষা করুন (কিছু মিনিটের মধ্যে ক্লাস্টার তৈরি হয়ে যাবে)।

---

## ⏸️ 3. MongoDB Connection String

একটি নতুন ক্লাস্টার তৈরি হওয়ার পর, আপনি কানেক্ট করার জন্য `Connection String` পাবেন। এটি কিছুটা এরকম হবে:

```
mongodb+srv://<username>:<password>@cluster0.mongodb.net/myDatabase?retryWrites=true&w=majority
```

**উল্লেখ্য**:
- `<username>`: আপনার MongoDB Atlas অ্যাকাউন্টের ইউজারনেম।
- `<password>`: আপনার MongoDB Atlas অ্যাকাউন্টের পাসওয়ার্ড।
- `myDatabase`: ডাটাবেস নাম যা আপনি তৈরি করতে চান।

এই কনেকশন স্ট্রিংটি আপনার প্রোজেক্টে ব্যবহার করতে হবে।

---

## ⏸️ 4. Node.js এ MongoDB ব্যবহার করার জন্য Mongoose ইনস্টল করুন

MongoDB-এর সাথে সহজে কাজ করার জন্য আমরা Mongoose ব্যবহার করব। Mongoose একটি জনপ্রিয় ODM (Object Document Mapping) লাইব্রেরি যা MongoDB ডাটাবেসের সাথে কাজ করার জন্য সাহায্য করে। 

প্রথমে `mongoose` ইনস্টল করুন:

```bash
npm install mongoose
```

---

## ⏸️ 5. MongoDB Atlas এর সাথে কানেক্ট করা

এখন, আপনার `server.js` বা অন্য কোন ফাইলের মধ্যে Mongoose ব্যবহার করে MongoDB Atlas-এর সাথে কানেক্ট করুন।

```js
const mongoose = require('mongoose');

const dbURI = 'mongodb+srv://<username>:<password>@cluster0.mongodb.net/myDatabase?retryWrites=true&w=majority';

mongoose.connect(dbURI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB Atlas connected!'))
  .catch((err) => console.log('Error connecting to MongoDB Atlas:', err));
```

এখানে, `dbURI`-তে আপনার MongoDB Atlas এর কনেকশন স্ট্রিং ব্যবহার করবেন। যদি কানেকশন সফল হয়, তাহলে "MongoDB Atlas connected!" মেসেজটি কনসোলে দেখাবে।

---

## ⏸️ 6. MongoDB Connection সফলতা যাচাই

MongoDB Atlas-এর সাথে কানেক্ট হওয়ার পর, আপনি নিচের কোডটি ব্যবহার করে কানেকশন যাচাই করতে পারেন:

```js
mongoose.connection.once('open', () => {
  console.log('Successfully connected to MongoDB Atlas');
}).on('error', (err) => {
  console.log('Connection error:', err);
});
```

এই কোডটি MongoDB সার্ভারের সাথে সফল সংযোগ নিশ্চিত করবে এবং যদি কোনো সমস্যা থাকে, সেটি দেখাবে।

---

## ⏸️ 7. Create MongoDB Schema

MongoDB ডাটাবেসে ডেটা সংরক্ষণের জন্য একটি Schema তৈরি করতে হবে। এটি একটি টেমপ্লেটের মতো কাজ করবে যা ডেটার গঠন নির্ধারণ করবে।

```js
const productSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true
  },
  price: {
    type: Number,
    required: true
  }
});

const Product = mongoose.model('Product', productSchema);
```

এখন, `Product` মডেলটি আপনার MongoDB ডাটাবেসে `products` কালেকশনে ডেটা সংরক্ষণ করবে।

---

## ⏸️ 8. Create a Product

MongoDB Atlas-এর সাথে সংযোগ হওয়ার পর, আপনি নতুন একটি পণ্য তৈরি করতে পারেন। নিচের কোডটি ব্যবহার করুন:

```js
const newProduct = new Product({
  name: 'Product 1',
  price: 100
});

newProduct.save()
  .then((product) => console.log('Product saved:', product))
  .catch((err) => console.log('Error saving product:', err));
```

এই কোডটি `Product` মডেলের একটি নতুন ডকুমেন্ট MongoDB ডাটাবেসে সেভ করবে।

---

## ⏸️ 9. Testing the Setup

এখন আপনি আপনার MongoDB Atlas কানেকশন এবং Schema তৈরি করার পর, Postman বা অন্য API টেস্টিং টুল ব্যবহার করে আপনার API টেস্ট করতে পারেন। MongoDB ডাটাবেসে সেভ হওয়া ডেটা দেখতে পারেন।

---

## 📌 In Short:

- **MongoDB Atlas**: MongoDB Atlas এ ক্লাউড ডাটাবেস তৈরি করা এবং সেটআপ করা।
- **Mongoose**: MongoDB এর সাথে সংযোগ স্থাপন করতে `Mongoose` ব্যবহার করা।
- **MongoDB Schema**: MongoDB ডাটাবেসে ডেটা সংরক্ষণের জন্য Schema তৈরি করা।
- **Create and Save Data**: MongoDB ডাটাবেসে ডেটা তৈরি করা এবং সেভ করা।

আজকের দিনটি শেষ! পরবর্তী দিন থেকে আরও উন্নত MongoDB ফিচার ব্যবহার করা হবে। 🚀






# Day 23

✅ **আজকের দিনটি MongoDB Schema এবং Model তৈরি করার উপর ভিত্তি করে।**  
আজকের লক্ষ্য হচ্ছে MongoDB-তে Schema এবং Model তৈরি করা। Schema হলো একটি টেমপ্লেট যা ডাটাবেসে ডেটার কাঠামো নির্ধারণ করে, এবং Model হলো MongoDB ডাটাবেসের সাথে ইন্টারঅ্যাক্ট করার জন্য ব্যবহৃত একটি কনভেনিয়েন্স লাইব্রেরি।

---

## ⏸️ 1. Schema কি?

MongoDB-তে Schema একটি কনস্ট্রেইন্ট বা ব্লুপ্রিন্ট হিসাবে কাজ করে, যা ডেটার কাঠামো এবং টাইপ নির্ধারণ করে। Schema-তে আপনি ডেটার প্রপার্টি, তার টাইপ এবং অন্যান্য বৈশিষ্ট্য নির্ধারণ করতে পারেন।

---

## ⏸️ 2. Model কি?

Model হলো MongoDB ডাটাবেসের সাথে ইন্টারঅ্যাক্ট করার জন্য একটি ক্লাস বা কনসেপ্ট। Model ব্যবহার করে আমরা MongoDB ডাটাবেসে ডেটা সেভ, আপডেট, ডিলিট, এবং ফেচ করতে পারি। 

Model তৈরি করতে আমরা Schema ব্যবহার করি। MongoDB Schema এবং Model তৈরি করার জন্য **Mongoose** ব্যবহার করা হয়।

---

## ⏸️ 3. MongoDB Schema তৈরি করা

একটি Schema তৈরি করতে আপনি Mongoose-এ `Schema` ক্লাস ব্যবহার করবেন। নিচে একটি সাধারণ Schema তৈরি করার উদাহরণ দেওয়া হলো।

```js
const mongoose = require('mongoose');

// Product Schema তৈরি করা
const productSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true, // নামটি অবশ্যই থাকতে হবে
  },
  price: {
    type: Number,
    required: true, // মূল্য অবশ্যই থাকতে হবে
  },
  description: {
    type: String,
    required: false, // বর্ণনা ঐচ্ছিক
  },
  category: {
    type: String,
    required: false, // ক্যাটেগরি ঐচ্ছিক
  },
  inStock: {
    type: Boolean,
    default: true, // ডিফল্টভাবে পণ্যটি স্টকে রয়েছে
  },
});

module.exports = mongoose.model('Product', productSchema);
```

এখানে:
- `name`, `price`, `description`, `category`, এবং `inStock` পণ্য সম্পর্কিত প্রপার্টি।
- `required: true` এর মাধ্যমে আমরা সেটি নির্দেশ করছি যে, এই ফিল্ডটি অবশ্যই থাকা দরকার।
- `default: true` দ্বারা ডিফল্ট মান দেওয়া হচ্ছে যদি `inStock` ফিল্ডে কোন মান না দেওয়া হয়।

---

## ⏸️ 4. MongoDB Model তৈরি করা

Model তৈরি করার জন্য আমরা `mongoose.model()` মেথড ব্যবহার করি। এটি আমাদের Schema কে MongoDB ডাটাবেসে একটি মডেলে রূপান্তরিত করে। 

```js
const mongoose = require('mongoose');

// Model তৈরি করা
const Product = mongoose.model('Product', productSchema);

// একটি নতুন পণ্য তৈরি এবং সেভ করা
const newProduct = new Product({
  name: 'Smartphone',
  price: 299,
  description: 'Latest model with high-end features.',
  category: 'Electronics',
});

newProduct.save()
  .then(() => console.log('Product saved successfully!'))
  .catch((err) => console.log('Error saving product:', err));
```

এখানে:
- `Product` মডেলটি আমাদের `productSchema` কে MongoDB ডাটাবেসের সাথে সংযুক্ত করেছে।
- `new Product()` ব্যবহার করে নতুন একটি ডকুমেন্ট তৈরি করা হয়েছে এবং `.save()` মেথড ব্যবহার করে MongoDB ডাটাবেসে সেভ করা হয়েছে।

---

## ⏸️ 5. Data Fetching from MongoDB

MongoDB ডাটাবেস থেকে ডেটা ফেচ করার জন্য Model ব্যবহার করা হয়। নিচে একটি উদাহরণ দেওয়া হলো:

```js
Product.find({ category: 'Electronics' })
  .then((products) => {
    console.log('Found products:', products);
  })
  .catch((err) => {
    console.log('Error fetching products:', err);
  });
```

এখানে:
- `Product.find()` মেথডটি MongoDB ডাটাবেস থেকে `category: 'Electronics'` অনুযায়ী ডেটা খুঁজে বের করবে এবং ফলাফল রিটার্ন করবে।

---

## ⏸️ 6. Data Update in MongoDB

MongoDB ডাটাবেসে ডেটা আপডেট করার জন্য `updateOne()` বা `updateMany()` মেথড ব্যবহার করা হয়।

```js
Product.updateOne(
  { name: 'Smartphone' }, // কনডিশন
  { $set: { price: 350 } } // আপডেট
)
  .then(() => console.log('Product updated successfully!'))
  .catch((err) => console.log('Error updating product:', err));
```

এখানে:
- `updateOne()` মেথডটি একটি নির্দিষ্ট ডকুমেন্ট আপডেট করবে যেখানে পণ্যের নাম `Smartphone` এবং মূল্য পরিবর্তন করবে।

---

## ⏸️ 7. Data Deletion in MongoDB

MongoDB ডাটাবেস থেকে ডেটা মুছতে `deleteOne()` বা `deleteMany()` মেথড ব্যবহার করা হয়।

```js
Product.deleteOne({ name: 'Smartphone' })
  .then(() => console.log('Product deleted successfully!'))
  .catch((err) => console.log('Error deleting product:', err));
```

এখানে:
- `deleteOne()` মেথডটি পণ্যের নাম `Smartphone` এর ডকুমেন্ট মুছে ফেলবে।

---

## 📌 In Short:

- **Schema**: MongoDB-তে Schema তৈরি করা যা ডেটার কাঠামো নির্ধারণ করে।
- **Model**: MongoDB ডাটাবেসে Schema এর উপর ভিত্তি করে Model তৈরি করা, যা ডেটা সেভ, আপডেট, এবং ডিলিট করতে ব্যবহৃত হয়।
- **CRUD Operations**: ডেটা তৈরি, পড়া, আপডেট এবং মুছে ফেলার পদ্ধতি শিখলেন।

আজকের দিনটি শেষ! পরবর্তী দিনে আমরা MongoDB-এর আরও উন্নত ফিচার এবং অপারেশন নিয়ে আলোচনা করব। 🚀






# Day 24

✅ **আজকের দিনটি MongoDB-তে Create, Read, Update, Delete (CRUD) অপারেশন নিয়ে।**  
আজকের লক্ষ্য হলো MongoDB ডাটাবেসে CRUD অপারেশনগুলি প্রয়োগ করা। CRUD হলো:  
- **Create**: নতুন ডেটা তৈরি করা  
- **Read**: ডেটা পড়া  
- **Update**: ডেটা আপডেট করা  
- **Delete**: ডেটা মুছে ফেলা

---

## ⏸️ 1. Create Operation (নতুন ডেটা তৈরি করা)

MongoDB-তে নতুন ডেটা তৈরি করতে আমরা মডেল ব্যবহার করে একটি নতুন ডকুমেন্ট তৈরি করি এবং `.save()` মেথড ব্যবহার করে সেটি ডাটাবেসে সেভ করি।

```js
const Product = require('./models/Product'); // Model import করা

// নতুন পণ্য তৈরি করা
const newProduct = new Product({
  name: 'Smartwatch',
  price: 150,
  description: 'A stylish and smart wristwatch.',
  category: 'Wearables',
  inStock: true,
});

// পণ্যটি সেভ করা
newProduct.save()
  .then(() => console.log('Product added successfully!'))
  .catch((err) => console.log('Error adding product:', err));
```

এখানে:
- `Product` মডেল ব্যবহার করে একটি নতুন পণ্য তৈরি করা হয়েছে।
- `.save()` মেথড ব্যবহার করে MongoDB ডাটাবেসে পণ্যটি সেভ করা হয়েছে।

---

## ⏸️ 2. Read Operation (ডেটা পড়া)

MongoDB-তে ডেটা পড়তে আমরা `.find()` বা `.findOne()` মেথড ব্যবহার করতে পারি। নিচে একটি উদাহরণ দেখানো হলো যেখানে `category` অনুযায়ী পণ্যগুলো পড়া হচ্ছে।

```js
Product.find({ category: 'Wearables' })
  .then((products) => {
    console.log('Found products:', products);
  })
  .catch((err) => {
    console.log('Error fetching products:', err);
  });
```

এখানে:
- `Product.find()` মেথডটি `category: 'Wearables'` এর উপর ভিত্তি করে ডেটা খুঁজে বের করবে।
- `.then()` ব্লকটি সফলভাবে ডেটা রিটার্ন করলে কাজ করবে।

---

## ⏸️ 3. Update Operation (ডেটা আপডেট করা)

MongoDB-তে ডেটা আপডেট করতে আমরা `.updateOne()` বা `.updateMany()` মেথড ব্যবহার করতে পারি। নিচে একটি উদাহরণ দেখানো হলো যেখানে একটি পণ্যের মূল্য আপডেট করা হচ্ছে।

```js
Product.updateOne(
  { name: 'Smartwatch' }, // পণ্যের নাম অনুসারে খুঁজে বের করা
  { $set: { price: 200 } } // মূল্য আপডেট করা
)
  .then(() => console.log('Product updated successfully!'))
  .catch((err) => console.log('Error updating product:', err));
```

এখানে:
- `updateOne()` মেথডটি পণ্যের নাম `Smartwatch` অনুসারে ডকুমেন্ট খুঁজে বের করবে এবং তার মূল্য ২০০ টাকা সেট করবে।
- `$set` অপারেটর ব্যবহার করে আমরা ফিল্ডের মান আপডেট করি।

---

## ⏸️ 4. Delete Operation (ডেটা মুছে ফেলা)

MongoDB-তে ডেটা মুছতে আমরা `.deleteOne()` বা `.deleteMany()` মেথড ব্যবহার করতে পারি। নিচে একটি উদাহরণ দেখানো হলো যেখানে একটি পণ্য মুছে ফেলা হচ্ছে।

```js
Product.deleteOne({ name: 'Smartwatch' })
  .then(() => console.log('Product deleted successfully!'))
  .catch((err) => console.log('Error deleting product:', err));
```

এখানে:
- `deleteOne()` মেথডটি পণ্যের নাম `Smartwatch` অনুযায়ী ডকুমেন্টটি ডিলিট করবে।

---

## 📌 In Short:

- **Create**: MongoDB-তে নতুন ডেটা তৈরি করার জন্য `new` এবং `.save()` ব্যবহার।
- **Read**: ডেটা পড়তে `.find()` এবং `.findOne()` ব্যবহার করা।
- **Update**: ডেটা আপডেট করতে `.updateOne()` এবং `$set` অপারেটর ব্যবহার করা।
- **Delete**: ডেটা মুছতে `.deleteOne()` ব্যবহার করা।

আজকের দিনটি শেষ! পরবর্তী দিনে আমরা MongoDB-এর আরও উন্নত ফিচার নিয়ে কাজ করব। 🚀





# Day 25

✅ **আজকের দিনটি MongoDB Schema-এর প্রাথমিক এবং অপ্রাথমিক টাইপ নিয়ে।**  
MongoDB-তে ডেটার বিভিন্ন ধরনের তথ্য সংরক্ষণ করা হয় এবং সেগুলি নির্দিষ্ট কাঠামো অনুযায়ী Schema-তে সংজ্ঞায়িত করা হয়। এই দিনটিতে আমরা MongoDB Schema-এর প্রাথমিক (primitive) এবং অপ্রাথমিক (non-primitive) ডেটা টাইপ নিয়ে আলোচনা করব।

---

## ⏸️ 1. Primitives Schema Types (প্রাথমিক টাইপ)

MongoDB-তে কিছু প্রাথমিক ডেটা টাইপ রয়েছে যেগুলি সাধারণত একক মান ধারণ করে। এগুলি প্রাথমিক বা primitive types হিসেবে পরিচিত। প্রধান প্রাথমিক টাইপগুলি হল:

### String (স্ট্রিং)

এটি টেক্সটের ডেটা ধারণ করে। স্ট্রিং টাইপ একটি সাধারণ টাইপ যা অক্ষরের সিকোয়েন্স ধারণ করে।

```js
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
});
```

### Number (সংখ্যা)

এটি সংখ্যা (ইন্টিজার বা দশমিক) ধারণ করে।

```js
const productSchema = new mongoose.Schema({
  price: { type: Number, required: true },
});
```

### Boolean (বুলিয়ান)

এটি দুটি মান ধারণ করে: `true` বা `false`।

```js
const userSchema = new mongoose.Schema({
  isActive: { type: Boolean, default: true },
});
```

### Date (তারিখ)

এটি তারিখ এবং সময় ধারণ করে।

```js
const eventSchema = new mongoose.Schema({
  eventDate: { type: Date, required: true },
});
```

### Buffer (বাফার)

এটি বাইনারি ডেটা ধারণ করতে ব্যবহৃত হয়, যেমন ইমেজ বা ফাইল।

```js
const imageSchema = new mongoose.Schema({
  imageData: { type: Buffer },
});
```

### Mixed (মিশ্র)

এটি যেকোনো ধরনের ডেটা ধারণ করতে পারে (যেমন স্ট্রিং, নম্বর, অ্যারে ইত্যাদি)। এটি একটি জেনেরিক টাইপ।

```js
const productSchema = new mongoose.Schema({
  details: { type: mongoose.Schema.Types.Mixed },
});
```

---

## ⏸️ 2. Non-primitive Schema Types (অপ্রাথমিক টাইপ)

MongoDB-তে কিছু অপ্রাথমিক বা non-primitive টাইপ রয়েছে যেগুলি আরও জটিল ডেটা স্ট্রাকচার ধারণ করতে সাহায্য করে। এগুলি সাধারণত একাধিক মান ধারণ করে। প্রধান অপ্রাথমিক টাইপগুলি হল:

### Array (অ্যারে)

এটি একাধিক মান ধারণ করতে ব্যবহৃত হয়। অ্যারে টাইপের মধ্যে বিভিন্ন ধরনের ডেটা থাকতে পারে।

```js
const userSchema = new mongoose.Schema({
  hobbies: { type: [String] }, // এটি স্ট্রিং ধরনের একাধিক মান ধারণ করতে পারে
});
```

### Object (অবজেক্ট)

এটি একটি অবজেক্ট বা JSON স্ট্রাকচার ধারণ করে, যাতে একাধিক প্রপার্টি থাকে।

```js
const userSchema = new mongoose.Schema({
  address: {
    street: { type: String },
    city: { type: String },
    postalCode: { type: String },
  },
});
```

### ObjectId (অবজেক্ট আইডি)

এটি MongoDB ডাটাবেসে অন্য একটি ডকুমেন্টের আইডি হিসেবে কাজ করে। এটি দুটি ডকুমেন্টের মধ্যে সম্পর্ক স্থাপন করতে ব্যবহৃত হয়।

```js
const orderSchema = new mongoose.Schema({
  product: { type: mongoose.Schema.Types.ObjectId, ref: 'Product' },
});
```

এখানে:
- `product` ফিল্ডটি একটি ObjectId টাইপ যা `Product` মডেলকে রেফারেন্স করছে।

### Buffer (বাফার)

যদিও বাফার টাইপটি প্রাথমিক টাইপ হিসেবে উল্লেখ করা হয়েছিল, তবে এটি কিছু ক্ষেত্রে non-primitive ডেটা হিসেবে ব্যবহৃত হতে পারে।

---

## ⏸️ 3. Schema Types-এর ব্যবহার

MongoDB Schema-তে টাইপ নির্ধারণ করে আপনি নিশ্চিত করতে পারেন যে, আপনার ডাটাবেসে কোনো ডেটা ভ্যালিড ফর্ম্যাটে আছে। উদাহরণস্বরূপ:

```js
const userSchema = new mongoose.Schema({
  name: { type: String, required: true },
  age: { type: Number, required: true },
  hobbies: { type: [String] }, // অ্যারে টাইপ
  address: {                   // অবজেক্ট টাইপ
    street: { type: String },
    city: { type: String },
  },
});
```

এখানে:
- `name` এবং `age` প্রাথমিক টাইপ হিসেবে `String` এবং `Number`।
- `hobbies` অ্যারে টাইপে সঞ্চিত হচ্ছে একাধিক স্ট্রিং।
- `address` একটি অবজেক্ট টাইপ।

---

## 📌 In Short:

- **প্রাথমিক টাইপ**: MongoDB-তে String, Number, Boolean, Date, Buffer, Mixed টাইপের ব্যবহার শিখলেন।
- **অপ্রাথমিক টাইপ**: MongoDB-তে Array, Object, ObjectId, এবং Buffer টাইপের ব্যবহার শিখলেন।
- **Schema design**: MongoDB Schema-তে বিভিন্ন টাইপ ব্যবহার করে ডেটার কাঠামো নির্ধারণ করার কৌশল শিখলেন।

আজকের দিনটি শেষ! পরবর্তী দিনে আমরা MongoDB Schema-এর আরও বিস্তারিত বিষয় নিয়ে আলোচনা করব। 🚀






# Day 26

✅ **আজকের দিনটি MongoDB-তে বিভিন্ন ধরনের কুয়েরি নিয়ে।**  
MongoDB-তে ডেটা সন্ধান করতে এবং সংশোধন করতে বিভিন্ন ধরনের কুয়েরি ব্যবহার করা হয়। আজকের দিনে আমরা MongoDB-এর সাধারণ কুয়েরি অপারেশনগুলি শিখব এবং তা কীভাবে ব্যবহার করতে হয়, তা দেখব।

---

## ⏸️ 1. `find()` কুয়েরি (ডেটা খুঁজে বের করা)

MongoDB-তে ডেটা খুঁজে বের করার জন্য সবচেয়ে সাধারণ কুয়েরি হল `find()`। এটি সমস্ত মিলানো ডেটার একটি অ্যারে ফেরত দেয়।

### উদাহরণ: সব পণ্য খুঁজে বের করা

```js
Product.find()
  .then((products) => {
    console.log('All Products:', products);
  })
  .catch((err) => {
    console.log('Error fetching products:', err);
  });
```

এখানে:
- `find()` মেথডটি সব পণ্য ডেটা ফেরত দেয়।
- `.then()` ব্লকটি ডেটা সফলভাবে পাওয়া গেলে কাজ করবে।

---

## ⏸️ 2. `findOne()` কুয়েরি (একটি ডেটা খুঁজে বের করা)

যখন আপনি শুধুমাত্র একটিমাত্র ডেটা খুঁজতে চান, তখন `findOne()` ব্যবহার করতে পারেন। এটি একটি ডকুমেন্ট রিটার্ন করে যা কুয়েরির সাথে মিলে।

### উদাহরণ: একটি পণ্য খুঁজে বের করা তার নাম অনুযায়ী

```js
Product.findOne({ name: 'Smartwatch' })
  .then((product) => {
    console.log('Product found:', product);
  })
  .catch((err) => {
    console.log('Error fetching product:', err);
  });
```

এখানে:
- `findOne()` মেথডটি `name` ফিল্ডে 'Smartwatch' অনুসারে একটি পণ্য খুঁজে বের করবে।

---

## ⏸️ 3. `findById()` কুয়েরি (ID দিয়ে ডেটা খুঁজে বের করা)

MongoDB-তে প্রতিটি ডকুমেন্টের একটি `_id` থাকে, যার মাধ্যমে আপনি নির্দিষ্ট ডেটা খুঁজে পেতে পারেন। `findById()` কুয়েরি ID দ্বারা ডেটা খুঁজে বের করে।

### উদাহরণ: একটি পণ্য খুঁজে বের করা তার ID দিয়ে

```js
const productId = '60d6c71d5e1f843eb8d7a098'; // আপনার প্রোডাক্ট ID

Product.findById(productId)
  .then((product) => {
    console.log('Product found by ID:', product);
  })
  .catch((err) => {
    console.log('Error fetching product by ID:', err);
  });
```

এখানে:
- `findById()` মেথডটি `_id` অনুযায়ী পণ্যটি খুঁজে বের করবে।

---

## ⏸️ 4. `sort()` কুয়েরি (ডেটা সাজানো)

MongoDB-তে ডেটা সাজাতে `sort()` মেথড ব্যবহার করা হয়। এটি ডেটাকে একটি নির্দিষ্ট ফিল্ডের উপর ভিত্তি করে সাজিয়ে দেয়।

### উদাহরণ: দাম অনুযায়ী পণ্য সাজানো

```js
Product.find()
  .sort({ price: 1 }) // 1 মানে ascending order, -1 মানে descending order
  .then((products) => {
    console.log('Sorted Products by Price:', products);
  })
  .catch((err) => {
    console.log('Error sorting products:', err);
  });
```

এখানে:
- `sort()` মেথডটি পণ্যের দাম অনুযায়ী সাজানো হয়েছে। `1` দিয়ে ascending (ছোট থেকে বড়) এবং `-1` দিয়ে descending (বড় থেকে ছোট) করা হয়।

---

## ⏸️ 5. `limit()` কুয়েরি (ডেটা সীমাবদ্ধ করা)

MongoDB-তে একটি নির্দিষ্ট সংখ্যক ডেটা ফেরত পেতে `limit()` মেথড ব্যবহার করা হয়।

### উদাহরণ: সর্বোচ্চ 5 পণ্য খুঁজে বের করা

```js
Product.find()
  .limit(5)
  .then((products) => {
    console.log('Limited Products:', products);
  })
  .catch((err) => {
    console.log('Error fetching limited products:', err);
  });
```

এখানে:
- `limit(5)` দিয়ে আমরা সর্বোচ্চ ৫টি পণ্য খুঁজে বের করেছি।

---

## ⏸️ 6. `skip()` কুয়েরি (ডেটা স্কিপ করা)

MongoDB-তে কিছু ডেটা স্কিপ করতে এবং পরবর্তী অংশ নিয়ে কাজ করতে `skip()` ব্যবহার করা হয়। এটি সাধারণত পেজিনেশন এর ক্ষেত্রে ব্যবহৃত হয়।

### উদাহরণ: প্রথম 5টি পণ্য স্কিপ করে পরবর্তী 5টি পণ্য খুঁজে বের করা

```js
Product.find()
  .skip(5)
  .limit(5)
  .then((products) => {
    console.log('Skipped first 5 and fetched next 5 Products:', products);
  })
  .catch((err) => {
    console.log('Error skipping and fetching products:', err);
  });
```

এখানে:
- `skip(5)` প্রথম ৫টি ডেটা স্কিপ করবে এবং `limit(5)` পরবর্তী ৫টি ডেটা ফিরিয়ে দেবে।

---

## ⏸️ 7. `updateOne()` কুয়েরি (ডেটা আপডেট করা)

MongoDB-তে একটি নির্দিষ্ট ডেটা আপডেট করতে `updateOne()` মেথড ব্যবহার করা হয়।

### উদাহরণ: একটি পণ্যের দাম আপডেট করা

```js
Product.updateOne(
  { name: 'Smartwatch' }, // পণ্যের নাম
  { $set: { price: 200 } } // নতুন দাম সেট করা
)
  .then(() => {
    console.log('Product price updated successfully!');
  })
  .catch((err) => {
    console.log('Error updating product price:', err);
  });
```

এখানে:
- `updateOne()` মেথডটি পণ্যের নাম 'Smartwatch' অনুসারে একটিমাত্র ডকুমেন্ট আপডেট করবে।

---

## ⏸️ 8. `deleteOne()` কুয়েরি (ডেটা মুছে ফেলা)

MongoDB-তে একটি নির্দিষ্ট ডেটা মুছে ফেলতে `deleteOne()` মেথড ব্যবহার করা হয়।

### উদাহরণ: একটি পণ্য মুছে ফেলা

```js
Product.deleteOne({ name: 'Smartwatch' })
  .then(() => {
    console.log('Product deleted successfully!');
  })
  .catch((err) => {
    console.log('Error deleting product:', err);
  });
```

এখানে:
- `deleteOne()` মেথডটি পণ্যের নাম 'Smartwatch' অনুসারে ডেটাটি মুছে ফেলবে।

---

## 📌 In Short:

- **`find()`**: সমস্ত ডেটা খুঁজে বের করা।
- **`findOne()`**: একক ডেটা খুঁজে বের করা।
- **`findById()`**: ID দ্বারা ডেটা খুঁজে বের করা।
- **`sort()`**: ডেটা সাজানো।
- **`limit()`**: ডেটা সীমাবদ্ধ করা।
- **`skip()`**: কিছু ডেটা স্কিপ করা।
- **`updateOne()`**: ডেটা আপডেট করা।
- **`deleteOne()`**: ডেটা মুছে ফেলা।

আজকের দিনটি শেষ! পরবর্তী দিনে আমরা আরও কিছু উন্নত MongoDB কুয়েরি নিয়ে আলোচনা করব। 🚀






# Day 27

✅ **আজকের দিনটি Express-এ MongoDB সংযোগ এবং `.env` ফাইল ব্যবহার করে ডাটাবেস কনফিগারেশন।**

আজকের দিনে, আমরা শিখব কিভাবে Express অ্যাপ্লিকেশন MongoDB-এ সংযোগ স্থাপন করতে হয় এবং `.env` ফাইল ব্যবহার করে ডাটাবেস কনফিগারেশন সংরক্ষণ করতে হয়। `.env` ফাইলটি নিরাপদভাবে কনফিগারেশন তথ্য সংরক্ষণ করার জন্য ব্যবহার করা হয়, যেমন ডাটাবেস ইউজারনেম, পাসওয়ার্ড, এবং অন্যান্য গোপন তথ্য।

---

## ⏸️ 1. `.env` ফাইল তৈরি

প্রথমে আপনার প্রজেক্ট রুট ডিরেক্টরিতে একটি `.env` ফাইল তৈরি করুন। এই ফাইলে ডাটাবেস সংক্রান্ত কনফিগারেশন সংরক্ষণ করবেন।

### উদাহরণ: `.env` ফাইল কনফিগারেশন

```env
DB_URI=mongodb+srv://username:password@cluster.mongodb.net/mydatabase?retryWrites=true&w=majority
```

এখানে:
- `DB_URI` হল আপনার MongoDB Atlas কনফিগারেশন URI। আপনি MongoDB Atlas থেকে আপনার কনফিগারেশন URI পাবেন।

---

## ⏸️ 2. `.env` ফাইল লোড করা

`.env` ফাইলটি লোড করার জন্য `dotenv` প্যাকেজটি ব্যবহার করতে হবে। এটি ডট নোটেশন (key-value) ফর্ম্যাটে কনফিগারেশনগুলি লোড করবে।

### উদাহরণ: `dotenv` প্যাকেজ ইন্সটল ও ব্যবহার

```bash
npm install dotenv
```

এবার আপনার `app.js` বা `server.js` ফাইলে নিচের মতো কোড যোগ করুন:

```js
require('dotenv').config(); // .env ফাইল লোড করার জন্য
```

এটি `.env` ফাইলের সব কনফিগারেশন আপনার অ্যাপ্লিকেশনটিতে লোড করবে।

---

## ⏸️ 3. MongoDB সংযোগ

এখন আমরা MongoDB-এ সংযোগ করতে Mongoose ব্যবহার করব। Mongoose হল MongoDB-এর জন্য একটি Object Data Modeling (ODM) লাইব্রেরি যা MongoDB এর সাথে সহজে কাজ করতে সহায়তা করে।

### উদাহরণ: MongoDB সংযোগ

```js
const mongoose = require('mongoose');

// .env ফাইল থেকে DB_URI সংগ্রহ করা
const dbURI = process.env.DB_URI;

// MongoDB-এ সংযোগ স্থাপন করা
mongoose.connect(dbURI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => {
    console.log('MongoDB connected successfully!');
  })
  .catch((err) => {
    console.log('MongoDB connection error:', err);
  });
```

এখানে:
- `process.env.DB_URI` ব্যবহার করে আমরা `.env` ফাইল থেকে ডাটাবেসের URI নিয়ে MongoDB-এ সংযোগ করেছি।
- `mongoose.connect()` মেথডটি MongoDB-এ সংযোগ স্থাপন করে এবং `.then()` ব্লকটি সংযোগ সফল হলে চলে।

---

## ⏸️ 4. Express সার্ভার শুরু

এখন আমরা একটি Express সার্ভার সেটআপ করব, যা MongoDB এর সাথে সংযুক্ত হবে।

### উদাহরণ: Express সার্ভার সেটআপ

```js
const express = require('express');
const app = express();
const port = process.env.PORT || 3000; // .env থেকে PORT ব্যবহার করা

// MongoDB সংযোগ
require('./db'); // আমাদের MongoDB কনফিগারেশন ফাইল

app.get('/', (req, res) => {
  res.send('Hello, MongoDB is connected with Express!');
});

app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
```

এখানে:
- আমরা `require('./db')` দিয়ে MongoDB কনফিগারেশন ফাইলটিকে ইম্পোর্ট করেছি এবং ডাটাবেস সংযোগ স্থাপন করেছি।
- Express সার্ভারটি চালু করার জন্য `app.listen()` মেথড ব্যবহার করেছি, যা `3000` পোর্টে অ্যাপ্লিকেশন চালাবে।

---

## 📌 In Short:

- **`.env` ফাইল**: ডাটাবেস কনফিগারেশন সংরক্ষণের জন্য `.env` ফাইল ব্যবহার করা।
- **`dotenv` প্যাকেজ**: `.env` ফাইল থেকে কনফিগারেশন লোড করা।
- **MongoDB সংযোগ**: Mongoose ব্যবহার করে MongoDB-এ সংযোগ স্থাপন।
- **Express সার্ভার**: MongoDB সংযুক্ত করা এবং Express সার্ভার সেটআপ করা।

আজকের দিনের কাজ শেষ! পরবর্তী দিন MongoDB-র উন্নত কনফিগারেশন ও ব্যবহার নিয়ে আলোচনা করা হবে। 🚀






# Day 28

✅ **আজকের দিনটি: Mini Project - Todo List App (MongoDB + Express)**

আজকের দিনে, আমরা একটি ছোট প্রকল্প তৈরি করব যা MongoDB এবং Express ব্যবহার করে একটি Todo List অ্যাপ তৈরি করবে। এটি আপনার MongoDB ডাটাবেসে টাস্কগুলি সঞ্চয় করবে এবং Express ব্যবহার করে API তৈরি করবে যাতে আপনি টাস্ক যোগ, মুছে ফেলতে এবং তালিকাটি দেখতে পারেন।

---

## ⏸️ 1. প্রজেক্ট সেটআপ

প্রথমে, আমাদের প্রজেক্টের জন্য প্রয়োজনীয় প্যাকেজগুলি ইনস্টল করব।

### প্রয়োজনীয় প্যাকেজ ইন্সটল করুন

```bash
npm init -y
npm install express mongoose dotenv body-parser
```

- `express`: সার্ভার তৈরি করতে।
- `mongoose`: MongoDB এর সাথে যোগাযোগ করতে।
- `dotenv`: কনফিগারেশন তথ্য লোড করতে।
- `body-parser`: POST রিকোয়েস্টের বডি পার্স করার জন্য।

---

## ⏸️ 2. `.env` ফাইল কনফিগারেশন

MongoDB সংযোগের জন্য `.env` ফাইল তৈরি করুন এবং আপনার MongoDB Atlas কনফিগারেশন সংরক্ষণ করুন।

### `.env` ফাইল কনফিগারেশন

```env
DB_URI=mongodb+srv://username:password@cluster.mongodb.net/todoApp?retryWrites=true&w=majority
```

এখানে:
- `DB_URI` আপনার MongoDB Atlas এর URI। এটি আপনাকে MongoDB Atlas থেকে পাওয়া যাবে।

---

## ⏸️ 3. MongoDB মডেল তৈরি

MongoDB মডেল তৈরি করতে Mongoose ব্যবহার করব। আমাদের এখানে একটি Todo মডেল দরকার যা আমাদের টাস্কের তথ্য সংরক্ষণ করবে।

### `models/Todo.js`

```js
const mongoose = require('mongoose');

// Todo মডেল তৈরি
const todoSchema = new mongoose.Schema({
  task: {
    type: String,
    required: true,
  },
  completed: {
    type: Boolean,
    default: false,
  },
});

const Todo = mongoose.model('Todo', todoSchema);

module.exports = Todo;
```

এখানে:
- `task`: টাস্কের নাম (স্ট্রিং)।
- `completed`: টাস্কের অবস্থান (Boolean)।

---

## ⏸️ 4. Express সার্ভার সেটআপ

এখন Express সার্ভার সেটআপ করব এবং MongoDB সংযোগ করব।

### `server.js`

```js
require('dotenv').config();
const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const Todo = require('./models/Todo');

const app = express();
const port = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());

// MongoDB সংযোগ
mongoose.connect(process.env.DB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log('MongoDB connection error:', err));

// API routes

// Get all todos
app.get('/todos', async (req, res) => {
  try {
    const todos = await Todo.find();
    res.json(todos);
  } catch (err) {
    res.status(500).send(err);
  }
});

// Add a new todo
app.post('/todos', async (req, res) => {
  const newTodo = new Todo({
    task: req.body.task,
  });

  try {
    const savedTodo = await newTodo.save();
    res.json(savedTodo);
  } catch (err) {
    res.status(400).send(err);
  }
});

// Update a todo
app.put('/todos/:id', async (req, res) => {
  try {
    const updatedTodo = await Todo.findByIdAndUpdate(req.params.id, req.body, { new: true });
    res.json(updatedTodo);
  } catch (err) {
    res.status(400).send(err);
  }
});

// Delete a todo
app.delete('/todos/:id', async (req, res) => {
  try {
    await Todo.findByIdAndDelete(req.params.id);
    res.send('Todo deleted');
  } catch (err) {
    res.status(400).send(err);
  }
});

// Start server
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
```

এখানে:
- `GET /todos`: সব টাস্কের তালিকা দেখায়।
- `POST /todos`: একটি নতুন টাস্ক তৈরি করে।
- `PUT /todos/:id`: একটি টাস্ক আপডেট করে।
- `DELETE /todos/:id`: একটি টাস্ক মুছে ফেলে।

---

## ⏸️ 5. পরীক্ষা

এখন, আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে এই API গুলি পরীক্ষা করতে পারেন।

- **GET** `/todos`: টাস্কের তালিকা দেখার জন্য।
- **POST** `/todos`: নতুন টাস্ক যোগ করতে। উদাহরণ:

  ```json
  {
    "task": "Learn Express"
  }
  ```

- **PUT** `/todos/:id`: একটি টাস্কের স্টেটাস পরিবর্তন করতে বা টাস্কের নাম পরিবর্তন করতে।
- **DELETE** `/todos/:id`: একটি টাস্ক মুছে ফেলতে।

---

## 📌 In Short:

- **MongoDB সংযোগ**: Express অ্যাপ্লিকেশন থেকে MongoDB এর সাথে সংযোগ স্থাপন করা।
- **Mongoose মডেল**: MongoDB এ টাস্কগুলি সংরক্ষণ করতে Mongoose মডেল তৈরি করা।
- **Express API**: GET, POST, PUT, DELETE রাউট ব্যবহার করে টাস্কগুলি পরিচালনা করা।
- **Mini Project**: Todo List অ্যাপ তৈরি করে API-র মাধ্যমে MongoDB ডাটাবেসে ডেটা পরিচালনা করা।

আজকের প্রকল্পের মাধ্যমে আপনি API রাউট তৈরি করার দক্ষতা অর্জন করেছেন। 🚀
```

