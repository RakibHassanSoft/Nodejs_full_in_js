# Day 15

✅ **আজকের দিনটি হবে Express ইনস্টল করা এবং রাউট তৈরি করার।**  
আজকে আমরা Express ফ্রেমওয়ার্ক ইনস্টল করবো এবং সেই সাথে একটি সিম্পল ওয়েব অ্যাপ্লিকেশন তৈরি করে বিভিন্ন রাউট তৈরি করার অনুশীলন করবো।

---

## ⏸️ 1. Express ইনস্টল করা

প্রথমে, আমাদের `Express` ফ্রেমওয়ার্ক ইনস্টল করতে হবে। Express হল একটি জনপ্রিয় Node.js ফ্রেমওয়ার্ক যা সার্ভার তৈরি করা এবং রাউটিং, মিডলওয়্যার ব্যবস্থাপনা সহজ করে তোলে।

### 1.1. Express ইনস্টল করার জন্য, প্রথমে আপনার প্রজেক্ট ডিরেক্টরিতে যান এবং নিচের কমান্ডটি চালান:

```bash
npm init -y
npm install express
```

এই কমান্ডটি `express` ইনস্টল করবে এবং আপনার `package.json` ফাইলে ডিপেনডেন্সি হিসেবে যোগ করবে।

---

## ⏸️ 2. Basic Express Server তৈরি করা

এখন আমরা একটি সিম্পল Express সার্ভার তৈরি করবো। সার্ভারটি HTTP রিকোয়েস্ট গ্রহণ করবে এবং সাড়া দিবে।

### 2.1. একটি `server.js` ফাইল তৈরি করুন এবং নিচের কোডটি লিখুন:

```js
// express মডিউলটি আমদানি করুন
const express = require('express');

// অ্যাপ তৈরি করুন
const app = express();

// রুট তৈরি করুন
app.get('/', (req, res) => {
  res.send('Hello World!'); // রেসপন্স হিসেবে "Hello World!" পাঠান
});

// সার্ভার চালু করুন
const port = 3000;
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
```

### 2.2. এখন, আপনার সার্ভারটি চালাতে নিম্নলিখিত কমান্ডটি চালান:

```bash
node server.js
```

এবার আপনি `http://localhost:3000`-এ গিয়ে দেখতে পারবেন যে "Hello World!" মেসেজটি প্রদর্শিত হচ্ছে।

---

## ⏸️ 3. রাউট তৈরি করা

Express এ রাউট তৈরি করা অত্যন্ত সহজ। আমরা বিভিন্ন HTTP মেথডের (GET, POST, PUT, DELETE) সাহায্যে রাউট তৈরি করতে পারি। চলুন, আমরা কিছু সাধারণ রাউট তৈরি করি।

### 3.1. **GET রাউট**:

GET রাউট সাধারণত ডাটা পেতে ব্যবহৃত হয়। আমরা পূর্বে তৈরি করা রুটটি `GET` রিকোয়েস্টের জন্য ব্যবহার করবো।

```js
app.get('/hello', (req, res) => {
  res.send('Hello from /hello route!');
});
```

এখন, আপনি `http://localhost:3000/hello`-এ গিয়ে "Hello from /hello route!" দেখতে পাবেন।

### 3.2. **POST রাউট**:

POST রাউটটি ব্যবহারকারীর ডাটা গ্রহণ করার জন্য ব্যবহৃত হয়। চলুন, একটি POST রাউট তৈরি করি যা ডাটা গ্রহণ করবে।

```js
app.post('/data', (req, res) => {
  res.send('Data received!');
});
```

এটি কাজ করতে, আপনাকে একটি HTTP POST রিকোয়েস্ট পাঠাতে হবে, যেমন Postman বা অন্যান্য API টুল ব্যবহার করে।

### 3.3. **PUT রাউট**:

PUT রাউটটি সাধারণত ডাটা আপডেট করার জন্য ব্যবহৃত হয়। চলুন, একটি PUT রাউট তৈরি করি।

```js
app.put('/update', (req, res) => {
  res.send('Data updated!');
});
```

### 3.4. **DELETE রাউট**:

DELETE রাউটটি সাধারণত ডাটা মুছে ফেলার জন্য ব্যবহৃত হয়। চলুন, একটি DELETE রাউট তৈরি করি।

```js
app.delete('/delete', (req, res) => {
  res.send('Data deleted!');
});
```

---

## ⏸️ 4. Middleware ব্যবহার করা

Express-এ **middleware** ব্যবহারের মাধ্যমে আমরা রিকোয়েস্ট এবং রেসপন্সের উপর অতিরিক্ত কাজ করতে পারি, যেমন লগিং, অথেনটিকেশন চেকিং, বা রিকোয়েস্ট বডি পার্সিং।

### 4.1. Express-এর বিল্ট-ইন `express.json()` মিডলওয়্যার ব্যবহার করে রিকোয়েস্ট বডি JSON ফর্ম্যাটে পার্স করতে পারেন:

```js
app.use(express.json());
```

এটি অ্যাপ্লিকেশনে যেকোনো রিকোয়েস্টের বডি JSON হিসেবে পার্স করবে, যাতে আপনি POST বা PUT রিকোয়েস্টে JSON ডাটা ব্যবহার করতে পারেন।

---

## 📌 In Short:

- **Express ফ্রেমওয়ার্ক ইনস্টল করা**: Express ইনস্টল করে একটি সিম্পল সার্ভার তৈরি করা।
- **GET, POST, PUT, DELETE রাউট তৈরি করা**: HTTP মেথডগুলো ব্যবহার করে রাউট তৈরি করা।
- **Middleware ব্যবহার**: রিকোয়েস্ট এবং রেসপন্সের ওপর অতিরিক্ত কাজ করার জন্য middleware ব্যবহার করা।

আজকের দিনে আপনি Express ব্যবহার করে সার্ভার এবং রাউট তৈরি করার মৌলিক ধারণা শিখেছেন। পরবর্তী দিনে আপনি আরও গভীরে Express এর অন্যান্য ফিচার নিয়ে কাজ করবেন।  
আজকের সেশন শেষ, পরবর্তী দিনে দেখা হবে! 🚀





# Day 16

✅ **আজকের দিনটি হবে Middleware এবং Error Handling নিয়ে কাজ করার।**  
আজকে আমরা Express এর **Middleware** এবং **Error Handling** সম্পর্কে বিস্তারিত আলোচনা করবো এবং কিভাবে এগুলি ব্যবহার করা যায় তা শিখবো।

---

## ⏸️ 1. Middleware পরিচিতি

**Middleware** হল Express অ্যাপ্লিকেশনের মধ্যে একটি ফাংশন, যা রিকোয়েস্ট এবং রেসপন্স চেইনের মধ্যে কাজ করে। এটি সাধারণত রিকোয়েস্ট হ্যান্ডলিংয়ের প্রক্রিয়ার মাঝে ব্যবহৃত হয়, এবং আমরা এটি ব্যবহার করে বিভিন্ন কাজ যেমন রিকোয়েস্ট ভ্যালিডেশন, লগিং, অথেনটিকেশন, এবং আরও অনেক কাজ করতে পারি।

### 1.1. **Middleware তৈরি করা**

Express-এ একটি সিম্পল Middleware তৈরি করতে নিম্নলিখিতভাবে কোড লিখা যায়:

```js
const myMiddleware = (req, res, next) => {
  console.log('Middleware triggered!');
  next(); // রিকোয়েস্ট চেইনে পরবর্তী ফাংশনে যাওয়ার জন্য next() কল করুন
};
```

এখন, এই Middleware কে আপনার অ্যাপ্লিকেশনে ব্যবহার করতে:

```js
app.use(myMiddleware);
```

এটি সমস্ত রিকোয়েস্টে কাজ করবে এবং লগ করবে "Middleware triggered!"।

### 1.2. **Specific রাউটের জন্য Middleware ব্যবহার করা**

আপনি চাইলে Middleware কে নির্দিষ্ট রাউটের জন্যও ব্যবহার করতে পারেন:

```js
app.get('/myroute', myMiddleware, (req, res) => {
  res.send('This route uses middleware!');
});
```

এখানে, `myMiddleware` শুধুমাত্র `/myroute` রাউটে কাজ করবে।

---

## ⏸️ 2. Error Handling

Express-এ **Error Handling** অত্যন্ত গুরুত্বপূর্ণ, কারণ এর মাধ্যমে আমরা অ্যাপ্লিকেশনের যেকোনো সমস্যা বা ভুল সঠিকভাবে হ্যান্ডেল করতে পারি। Express এ একটি সাধারণ error-handling middleware থাকে, যা রিকোয়েস্ট প্রক্রিয়াকরণ শেষে কল করা হয়।

### 2.1. **Error Handling Middleware তৈরি করা**

একটি সাধারণ error-handling middleware ফাংশন হল:

```js
app.use((err, req, res, next) => {
  console.error(err.stack);  // এরর স্ট্যাক কনসোলে লগ করুন
  res.status(500).send('Something went wrong!');  // 500 Internal Server Error
});
```

এই middleware তখন কল হবে যখন কোনো error ঘটবে এবং এটি সেই error এর স্ট্যাক দেখাবে এবং 500 স্ট্যাটাস কোড সহ একটি বার্তা রেসপন্স করবে।

### 2.2. **Error throw করা**

আপনি চাইলে কাস্টম error তৈরি করে সেগুলো throw করতে পারেন:

```js
app.get('/error', (req, res, next) => {
  const error = new Error('Custom Error Occurred!');
  next(error);  // পরবর্তী error-handling middleware-এ error পাঠান
});
```

এটি তখন error-handling middleware-এ চলে যাবে, যেখানে error হ্যান্ডেল করা হবে।

---

## ⏸️ 3. Custom Error Class তৈরি করা

আপনি যদি অনেকগুলো জায়গায় একই ধরনের error হ্যান্ডেল করতে চান, তাহলে একটি custom error class তৈরি করা ভালো। এর মাধ্যমে আপনি error এর বিস্তারিত ইনফরমেশন সঠিকভাবে manage করতে পারবেন।

### 3.1. **Custom Error Class তৈরি করা**

```js
class CustomError extends Error {
  constructor(statusCode, message) {
    super(message);
    this.statusCode = statusCode;
  }
}

app.get('/error', (req, res, next) => {
  const error = new CustomError(400, 'This is a custom error!');
  next(error);  // custom error object পাঠানো হচ্ছে
});
```

এখন, আমাদের error-handling middleware এ এই custom error কিভাবে handle করতে হবে তা নিচে দেখানো হলো:

```js
app.use((err, req, res, next) => {
  console.error(err.stack);  
  res.status(err.statusCode || 500).send(err.message || 'Something went wrong!');
});
```

এভাবে আমরা কাস্টম error তৈরি করে সেই error এর সাথে সম্পর্কিত তথ্য (যেমন statusCode) রেসপন্সে পাঠাতে পারি।

---

## ⏸️ 4. Third-party Middleware ব্যবহার করা

Express এ অনেকগুলি third-party middleware পাওয়া যায়, যেগুলি আমাদের প্রজেক্টের কাজ সহজ করে দেয়। এক্ষেত্রে, আমরা `morgan` middleware ব্যবহার করে HTTP রিকোয়েস্টের লগিং করতে পারি।

### 4.1. **Morgan Middleware ইনস্টল করা**

```bash
npm install morgan
```

এখন, `morgan` ব্যবহার করা:

```js
const morgan = require('morgan');
app.use(morgan('dev'));  // 'dev' স্টাইলের লগিং
```

এটি HTTP রিকোয়েস্টের লগ কনসোলে দেখাবে, যেমন:

```
GET / 200 15ms - 21B
```

---

## 📌 In Short:

- **Middleware**: Express অ্যাপ্লিকেশনে বিভিন্ন কাজ করার জন্য middleware ব্যবহার করার কৌশল।
- **Error Handling**: কিভাবে errors handle করা যায় এবং কাস্টম error তৈরি করা।
- **Custom Error Classes**: কাস্টম error class তৈরি করে সেগুলিকে অ্যাপ্লিকেশনে ব্যবহার করা।
- **Third-party Middleware**: `morgan` এর মতো third-party middleware ব্যবহার করা।

আজকের সেশনটি শেষ! পরবর্তী দিনে আরও কিছু advanced বিষয় নিয়ে আলোচনা করা হবে। 🚀




# Day 17

✅ **আজকের দিনটি হবে RESTful API তৈরি করার।**  
আজকে আমরা RESTful API কী এবং কিভাবে Express ব্যবহার করে একটি সিম্পল RESTful API তৈরি করা যায় তা শিখবো।

---

## ⏸️ 1. RESTful API কী?

**REST** (Representational State Transfer) হল একটি আর্কিটেকচারাল স্টাইল, যা ওয়েব সার্ভিস নির্মাণের জন্য একটি স্ট্যান্ডার্ড। RESTful API হল এমন একটি API যেটি HTTP প্রোটোকল ব্যবহার করে ডাটা সরবরাহ করে এবং CRUD (Create, Read, Update, Delete) অপারেশনগুলো সম্পাদন করে।

### 1.1. RESTful API এর মূল বৈশিষ্ট্য:
- **Stateless**: প্রতিটি রিকোয়েস্ট একে অপরের সাথে সম্পর্কিত নয়, অর্থাৎ সার্ভার কোনো ক্লায়েন্টের স্টেট সংরক্ষণ করে না।
- **Client-Server**: ক্লায়েন্ট এবং সার্ভারের মধ্যে স্পষ্ট পৃথকীকরণ রয়েছে।
- **Cacheable**: রেসপন্স গুলি ক্যাশযোগ্য হতে পারে।
- **Uniform Interface**: একটি নির্দিষ্ট ইন্টারফেস অনুসরণ করা হয়, যেমন GET, POST, PUT, DELETE।

---

## ⏸️ 2. API এর জন্য Routes তৈরি করা

RESTful API তৈরি করার জন্য প্রথমে আমাদের বিভিন্ন HTTP মেথডের (GET, POST, PUT, DELETE) মাধ্যমে রাউট তৈরি করতে হবে।

### 2.1. **GET রাউট**: ডাটা প্রাপ্তির জন্য

```js
app.get('/api/products', (req, res) => {
  res.json([
    { id: 1, name: 'Product 1', price: 100 },
    { id: 2, name: 'Product 2', price: 200 },
  ]);
});
```

এটি `/api/products` রাউটে GET রিকোয়েস্ট আসলে একটি প্রোডাক্টের তালিকা রেসপন্স করবে।

### 2.2. **POST রাউট**: নতুন ডাটা তৈরি করা

```js
app.post('/api/products', (req, res) => {
  const newProduct = req.body;  // POST রিকোয়েস্টের বডি থেকে নতুন প্রোডাক্ট
  res.status(201).json(newProduct);  // নতুন প্রোডাক্ট রেসপন্স হিসেবে ফেরত পাঠান
});
```

এটি `/api/products` রাউটে POST রিকোয়েস্ট পেলে নতুন একটি প্রোডাক্ট তৈরি করে রেসপন্স করবে।

### 2.3. **PUT রাউট**: ডাটা আপডেট করা

```js
app.put('/api/products/:id', (req, res) => {
  const productId = req.params.id;  // URL প্যারামিটার থেকে প্রোডাক্ট আইডি নেওয়া
  const updatedProduct = req.body;  // POST বা PUT রিকোয়েস্টের বডি থেকে আপডেট হওয়া ডাটা
  res.json({ id: productId, ...updatedProduct });  // আপডেট হওয়া প্রোডাক্ট রেসপন্স করা
});
```

এটি `/api/products/:id` রাউটে PUT রিকোয়েস্ট পেলে নির্দিষ্ট প্রোডাক্টের ডাটা আপডেট করে রেসপন্স করবে।

### 2.4. **DELETE রাউট**: ডাটা মুছে ফেলা

```js
app.delete('/api/products/:id', (req, res) => {
  const productId = req.params.id;  // URL প্যারামিটার থেকে প্রোডাক্ট আইডি নেওয়া
  res.status(204).send();  // কোনো কনটেন্ট না পাঠিয়ে 204 (No Content) স্ট্যাটাস রিটার্ন করা
});
```

এটি `/api/products/:id` রাউটে DELETE রিকোয়েস্ট পেলে প্রোডাক্ট মুছে ফেলে 204 রেসপন্স পাঠাবে।

---

## ⏸️ 3. Middleware ব্যবহার করা

RESTful API এর জন্য অনেক সময় আমাদের রিকোয়েস্ট ভ্যালিডেশন, অথেনটিকেশন, বা লগিং এর মতো কাজ করতে হয়। এজন্য আমরা Middleware ব্যবহার করতে পারি।

### 3.1. **Body Parsing Middleware**: POST বা PUT রিকোয়েস্টের বডি প্যার্স করার জন্য

```js
app.use(express.json());  // JSON বডি পার্স করার জন্য express.json() ব্যবহার করা হচ্ছে
```

### 3.2. **Custom Middleware**: API রিকোয়েস্ট লগিং

```js
const logRequest = (req, res, next) => {
  console.log(`${req.method} ${req.url}`);  // HTTP মেথড এবং URL লগ করুন
  next();  // পরবর্তী রাউটে রিকোয়েস্ট পাঠান
};

app.use(logRequest);  // সমস্ত রাউটে লগিং middleware ব্যবহার করা হচ্ছে
```

---

## ⏸️ 4. Error Handling

RESTful API তে error handling খুবই গুরুত্বপূর্ণ, বিশেষ করে যখন ডাটা না পাওয়া যায় বা সার্ভারে সমস্যা হয়। Express-এ আমরা error handling middleware ব্যবহার করে API এ error হ্যান্ডল করতে পারি।

### 4.1. **Error Handling Middleware**

```js
app.use((err, req, res, next) => {
  console.error(err.stack);  // এরর স্ট্যাক কনসোলে লগ করা হচ্ছে
  res.status(500).json({ error: 'Something went wrong!' });  // 500 Internal Server Error
});
```

এটি কোনো error হলে সেই error রেসপন্সে পাঠাবে এবং 500 স্ট্যাটাস কোড দিবে।

---

## 📌 In Short:

- **RESTful API**: কীভাবে Express ব্যবহার করে RESTful API তৈরি করা যায় এবং HTTP মেথডের মাধ্যমে CRUD অপারেশন সম্পাদন করা যায়।
- **Routes**: GET, POST, PUT, DELETE রাউট তৈরি করা।
- **Middleware**: রিকোয়েস্ট ভ্যালিডেশন, লগিং, বা অন্য কাজের জন্য middleware তৈরি করা।
- **Error Handling**: API তে error handling middleware ব্যবহার করা।

আজকের সেশনটি শেষ! পরবর্তী দিনে আরও উন্নত API ফিচার নিয়ে আলোচনা করা হবে। 🚀






# Day 18

✅ **আজকের দিনটি হবে Status Codes, JSON Responses, এবং Headers নিয়ে কাজ করার।**  
আজকে আমরা HTTP status codes, JSON রেসপন্স, এবং headers সম্পর্কে বিস্তারিত জানবো এবং কিভাবে Express অ্যাপ্লিকেশনে এগুলি ব্যবহার করা যায় তা শিখবো।

---

## ⏸️ 1. HTTP Status Codes

**HTTP Status Codes** হল এমন কোড যেগুলি সার্ভার ক্লায়েন্টকে রেসপন্স করার সময় পাঠায়। এই কোডগুলি রিকোয়েস্টের সফলতা বা ব্যর্থতার অবস্থা জানায়। HTTP স্ট্যাটাস কোডগুলির তিনটি প্রধান শ্রেণী রয়েছে:

- **1xx (Informational)**: রিকোয়েস্ট প্রক্রিয়াধীন আছে।
- **2xx (Success)**: রিকোয়েস্ট সফলভাবে প্রক্রিয়া করা হয়েছে।
- **3xx (Redirection)**: রিকোয়েস্টে কোনো পুনঃনির্দেশনা করা হয়েছে।
- **4xx (Client Error)**: ক্লায়েন্টের পক্ষ থেকে কোনো ভুল হয়েছে।
- **5xx (Server Error)**: সার্ভারের পক্ষ থেকে কোনো ভুল হয়েছে।

### 1.1. সাধারণ HTTP Status Codes:

- **200 OK**: রিকোয়েস্ট সফলভাবে সম্পন্ন হয়েছে।
- **201 Created**: রিকোয়েস্ট সফলভাবে সম্পন্ন হয়েছে এবং নতুন কিছু তৈরি হয়েছে।
- **400 Bad Request**: রিকোয়েস্ট সঠিক নয় বা সঠিকভাবে প্রক্রিয়া করা যায়নি।
- **404 Not Found**: রিকোয়েস্টকৃত রিসোর্স পাওয়া যায়নি।
- **500 Internal Server Error**: সার্ভারে কোনো ত্রুটি ঘটেছে।

---

## ⏸️ 2. JSON Responses

Express অ্যাপ্লিকেশনগুলিতে সাধারণত রেসপন্স JSON ফরম্যাটে পাঠানো হয়, বিশেষ করে API-তে। JSON রেসপন্স পাঠানোর জন্য `res.json()` মেথড ব্যবহার করা হয়।

### 2.1. **JSON Response পাঠানো**

```js
app.get('/api/products', (req, res) => {
  const products = [
    { id: 1, name: 'Product 1', price: 100 },
    { id: 2, name: 'Product 2', price: 200 },
  ];
  res.status(200).json(products);  // 200 OK status সহ JSON রেসপন্স পাঠানো
});
```

এখানে `/api/products` রাউটে GET রিকোয়েস্ট করলে একটি প্রোডাক্টের তালিকা JSON ফরম্যাটে রেসপন্স হিসেবে ফিরে আসবে।

### 2.2. **Error Response পাঠানো**

আপনি চাইলে ত্রুটি ঘটলে JSON রেসপন্স পাঠাতে পারেন:

```js
app.get('/api/product/:id', (req, res) => {
  const product = getProductById(req.params.id);  // Product খোঁজা হচ্ছে
  if (!product) {
    return res.status(404).json({ error: 'Product not found' });  // 404 Not Found status সহ JSON ত্রুটি রেসপন্স
  }
  res.status(200).json(product);  // Product পাওয়ার পর JSON রেসপন্স পাঠানো
});
```

এটি `404 Not Found` স্ট্যাটাস সহ একটি JSON ত্রুটি রেসপন্স পাঠাবে যদি প্রোডাক্টটি না পাওয়া যায়।

---

## ⏸️ 3. HTTP Headers

HTTP **headers** রিকোয়েস্ট বা রেসপন্স সম্পর্কে অতিরিক্ত তথ্য প্রদান করে। সাধারণত headers ব্যবহার করা হয় content type, authorization, বা অন্যান্য কনফিগারেশন সেট করতে।

### 3.1. **Headers সেট করা**

যখন আপনি কোনো রেসপন্স পাঠান, আপনি চাইলে বিভিন্ন header সেট করতে পারেন, যেমন `Content-Type`, `Authorization`, ইত্যাদি।

```js
app.get('/api/products', (req, res) => {
  res.set('Content-Type', 'application/json');  // Content-Type header সেট করা হচ্ছে
  res.status(200).json({ message: 'Products retrieved successfully' });
});
```

এখানে, `Content-Type` header সেট করা হয়েছে যাতে ক্লায়েন্ট জানে যে রেসপন্স JSON ফরম্যাটে পাঠানো হচ্ছে।

### 3.2. **Custom Headers**

কাস্টম headersও অ্যাড করা যেতে পারে:

```js
app.get('/api/user', (req, res) => {
  res.set('X-Custom-Header', 'CustomHeaderValue');  // কাস্টম header সেট করা হচ্ছে
  res.status(200).json({ message: 'User data retrieved successfully' });
});
```

এখানে `X-Custom-Header` নামে একটি কাস্টম header রেসপন্সে অ্যাড করা হয়েছে।

### 3.3. **Authorization Header**

API গুলিতে অনেক সময় `Authorization` header ব্যবহার করে অথেনটিকেশন করা হয়। উদাহরণস্বরূপ, JWT (JSON Web Token) ব্যবহার করে API অথেনটিকেশন করা:

```js
app.get('/api/protected', (req, res) => {
  const token = req.headers['authorization'];  // Authorization header থেকে token নেওয়া হচ্ছে
  if (!token) {
    return res.status(401).json({ error: 'Unauthorized' });
  }
  // JWT token যাচাই করার লজিক এখানে যাবে
  res.status(200).json({ message: 'Access granted to protected resource' });
});
```

এখানে, `Authorization` header থেকে JWT টোকেন নিয়ে API রিকোয়েস্ট যাচাই করা হচ্ছে।

---

## ⏸️ 4. Combining Status Codes, JSON Responses, and Headers

আপনি HTTP status codes, JSON রেসপন্স, এবং headers একসাথে ব্যবহার করতে পারেন একটি সুন্দর API রেসপন্স তৈরি করতে। নিচে একটি উদাহরণ দেয়া হল:

```js
app.post('/api/login', (req, res) => {
  const { username, password } = req.body;

  if (username !== 'user' || password !== 'password') {
    return res.status(401).json({ error: 'Invalid credentials' });  // 401 Unauthorized
  }

  const token = generateJWT(username);  // JWT টোকেন তৈরি করা হচ্ছে
  res.set('Authorization', `Bearer ${token}`);  // Authorization header এ token সেট করা হচ্ছে
  res.status(200).json({ message: 'Login successful', token });  // 200 OK status সহ JSON রেসপন্স পাঠানো
});
```

এখানে আমরা **401 Unauthorized** status, **JSON** রেসপন্স, এবং **Authorization** header একসাথে ব্যবহার করেছি।

---

## 📌 In Short:

- **HTTP Status Codes**: বিভিন্ন স্ট্যাটাস কোডের গুরুত্ব এবং সেগুলি কীভাবে Express API তে ব্যবহার করা যায়।
- **JSON Responses**: API তে JSON রেসপন্স পাঠানো এবং ত্রুটি রেসপন্স প্রদান।
- **HTTP Headers**: রেসপন্সে headers যেমন `Content-Type`, `Authorization` ইত্যাদি সেট করা।

আজকের সেশনটি শেষ! পরবর্তী দিনে আরও বিস্তারিতভাবে API নিরাপত্তা ও উন্নত ফিচার নিয়ে আলোচনা করা হবে। 🚀






# Day 19

✅ **আজকের দিনটি হবে Products CRUD API তৈরি করার।**  
আজকে আমরা Products সম্পর্কিত একটি CRUD (Create, Read, Update, Delete) API তৈরি করবো। Express অ্যাপ্লিকেশন ব্যবহার করে একটি সিম্পল প্রোডাক্ট ম্যানেজমেন্ট সিস্টেম তৈরি করবো, যেখানে আমরা প্রোডাক্ট যোগ, দেখানো, আপডেট, এবং মুছে ফেলার কার্যক্রম শিখবো।

---

## ⏸️ 1. Setup Express Server

প্রথমে, আমাদের Express অ্যাপ্লিকেশন সেটআপ করতে হবে:

```bash
npm init -y
npm install express mongoose body-parser
```

এখানে আমরা `express` এবং `mongoose` ইনস্টল করছি, যা MongoDB এর সাথে কাজ করতে সাহায্য করবে। `body-parser` ইনস্টল করছি যাতে আমরা POST রিকোয়েস্টের বডি ডেটা পেতে পারি।

### 1.1. Express Server তৈরি করা:

```js
const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());  // JSON বডি প্যারিং

mongoose.connect('mongodb://localhost/productsDB', {
  useNewUrlParser: true,
  useUnifiedTopology: true,
})
  .then(() => console.log('Database connected!'))
  .catch((err) => console.log('Database connection error:', err));

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
```

এখানে, আমরা `mongoose.connect()` ব্যবহার করে MongoDB এর সাথে কানেক্ট করেছি এবং Express সার্ভার চালু করেছি।

---

## ⏸️ 2. Create Product Model

MongoDB এর জন্য একটি `Product` মডেল তৈরি করি যাতে আমাদের প্রোডাক্টের ডাটা সেভ করা যাবে। 

```js
const mongoose = require('mongoose');

const productSchema = new mongoose.Schema({
  name: { type: String, required: true },
  price: { type: Number, required: true },
  description: { type: String, required: true },
});

const Product = mongoose.model('Product', productSchema);
module.exports = Product;
```

এখানে, আমরা একটি `Product` স্কিমা তৈরি করেছি, যেখানে `name`, `price`, এবং `description` ফিল্ডগুলি রয়েছে। আমরা এই মডেলটি পরে CRUD অপারেশন করতে ব্যবহার করবো।

---

## ⏸️ 3. Create Product (POST)

প্রথম CRUD অপারেশন হবে **Create**, যেখানে আমরা নতুন প্রোডাক্ট যুক্ত করব। 

```js
const Product = require('./models/Product');  // Product মডেল ইমপোর্ট

app.post('/api/products', (req, res) => {
  const { name, price, description } = req.body;

  const newProduct = new Product({ name, price, description });
  
  newProduct.save()
    .then((product) => res.status(201).json(product))  // 201 Created status সহ প্রোডাক্ট রেসপন্স
    .catch((err) => res.status(400).json({ error: err.message }));  // 400 Bad Request error রেসপন্স
});
```

এখানে আমরা `POST /api/products` রিকোয়েস্টের মাধ্যমে নতুন প্রোডাক্ট তৈরি করেছি এবং MongoDB এ সেভ করেছি।

---

## ⏸️ 4. Read Products (GET)

এবার আমরা **Read** অপারেশন করব, যেখানে সকল প্রোডাক্ট দেখাবো।

```js
app.get('/api/products', (req, res) => {
  Product.find()
    .then((products) => res.status(200).json(products))  // 200 OK status সহ প্রোডাক্ট তালিকা রেসপন্স
    .catch((err) => res.status(400).json({ error: err.message }));  // 400 Bad Request error রেসপন্স
});
```

এখানে, আমরা `GET /api/products` রিকোয়েস্টে সমস্ত প্রোডাক্টের তালিকা JSON ফরম্যাটে রেসপন্স হিসেবে পাঠিয়েছি।

---

## ⏸️ 5. Update Product (PUT)

এখন আমরা **Update** অপারেশন করবো, যেখানে একটি নির্দিষ্ট প্রোডাক্টের তথ্য আপডেট করা যাবে।

```js
app.put('/api/products/:id', (req, res) => {
  const { id } = req.params;
  const { name, price, description } = req.body;

  Product.findByIdAndUpdate(id, { name, price, description }, { new: true })
    .then((updatedProduct) => res.status(200).json(updatedProduct))  // 200 OK status সহ আপডেটেড প্রোডাক্ট রেসপন্স
    .catch((err) => res.status(400).json({ error: err.message }));  // 400 Bad Request error রেসপন্স
});
```

এখানে, আমরা `PUT /api/products/:id` রিকোয়েস্টের মাধ্যমে একটি নির্দিষ্ট প্রোডাক্টের তথ্য আপডেট করেছি।

---

## ⏸️ 6. Delete Product (DELETE)

সবশেষে, **Delete** অপারেশন করবো, যেখানে একটি প্রোডাক্ট মুছে ফেলা যাবে।

```js
app.delete('/api/products/:id', (req, res) => {
  const { id } = req.params;

  Product.findByIdAndDelete(id)
    .then(() => res.status(204).json())  // 204 No Content status রেসপন্স (কোনো কন্টেন্ট নেই)
    .catch((err) => res.status(400).json({ error: err.message }));  // 400 Bad Request error রেসপন্স
});
```

এখানে, আমরা `DELETE /api/products/:id` রিকোয়েস্টের মাধ্যমে একটি নির্দিষ্ট প্রোডাক্ট মুছে ফেলেছি।

---

## ⏸️ 7. Testing the CRUD Operations

আপনি Postman বা Insomnia ব্যবহার করে আপনার API টেস্ট করতে পারেন:

- **POST**: `/api/products` — নতুন প্রোডাক্ট যোগ করুন।
- **GET**: `/api/products` — প্রোডাক্টের তালিকা দেখুন।
- **PUT**: `/api/products/:id` — প্রোডাক্ট আপডেট করুন।
- **DELETE**: `/api/products/:id` — প্রোডাক্ট মুছে ফেলুন।

---

## 📌 In Short:

- **Create**: একটি নতুন প্রোডাক্ট যুক্ত করা।
- **Read**: সকল প্রোডাক্টের তালিকা দেখানো।
- **Update**: একটি প্রোডাক্টের তথ্য আপডেট করা।
- **Delete**: একটি প্রোডাক্ট মুছে ফেলা।

আজকের সেশনটি শেষ! পরবর্তী দিনে আরও উন্নত API ফিচার নিয়ে আলোচনা করা হবে। 🚀







# Day 20

✅ **আজকের দিনটি হবে একটি Practice session।**  
আজকে আপনি আপনার এখন পর্যন্ত শিখে নেওয়া সব কিছু নিয়ে একটি সার্বিক অনুশীলন করবেন। এটি আপনার প্রকল্পগুলোতে বাস্তবিকভাবে শিখা বিষয়গুলি প্রয়োগ করতে সহায়ক হবে। আপনাকে কিছু ছোট ছোট চ্যালেঞ্জ দেওয়া হবে, যা আপনাকে একসাথে কাজ করার মাধ্যমে দক্ষতা অর্জন করতে সহায়ক হবে। 

---

## ⏸️ 1. Create a Simple CRUD App

আজকে, আপনি একটি সিম্পল CRUD (Create, Read, Update, Delete) অ্যাপ তৈরি করবেন। আপনি এটি একটি "To-Do List" অ্যাপ হতে পারেন যেখানে ব্যবহারকারী টাস্ক যোগ করতে পারে, দেখতে পারে, সম্পাদনা করতে পারে এবং মুছে ফেলতে পারে। 

### Steps:
1. **Create a Product Model**: পূর্বের দিনে শিখা `Product` মডেলটি ব্যবহার করতে পারেন।
2. **Add Routes**: `POST`, `GET`, `PUT`, এবং `DELETE` রাউট তৈরি করুন।
3. **Use MongoDB**: মongodb ডাটাবেস ব্যবহার করতে পারেন টাস্কের জন্য। 

---

## ⏸️ 2. Error Handling Practice

এখন একটি অ্যাপ তৈরি করুন যেখানে বিভিন্ন ধরণের ভুল হতে পারে, যেমন:
- **Invalid Input**: ব্যবহারকারী ভুল ইনপুট দিলে সঠিক Error Message দিন।
- **Database Connection Failures**: MongoDB এর সাথে কানেক্ট না হলে সঠিক error handling করুন।

### Example:
```js
app.post('/api/tasks', (req, res) => {
  const { title, description } = req.body;
  
  if (!title || !description) {
    return res.status(400).json({ error: 'Title and description are required!' });
  }

  // task save logic goes here...
});
```

---

## ⏸️ 3. Practice with Asynchronous Operations

আপনি `async` এবং `await` ব্যবহার করে MongoDB বা অন্য API থেকে ডেটা ফেচ করতে পারেন। নিশ্চিত করুন যে আপনি `try` এবং `catch` ব্লকের মাধ্যমে সঠিকভাবে error handling করছেন। উদাহরণ:

```js
app.get('/api/tasks', async (req, res) => {
  try {
    const tasks = await Task.find();
    res.status(200).json(tasks);
  } catch (err) {
    res.status(500).json({ error: 'Something went wrong!' });
  }
});
```

---

## ⏸️ 4. Debugging Practice

আজকের দিনটি আপনার অ্যাপ্লিকেশন ডিবাগ করার জন্যও উপযুক্ত। কিছু ভুল বা সমস্যা হতে পারে, সেগুলো খুঁজে বের করে সমাধান করুন। এটি আপনাকে সমস্যা সমাধানে আরও দক্ষ করে তুলবে।

- **Console Log Statements**: যখনই কোনো সমস্যা দেখবেন, `console.log()` ব্যবহার করে দেখতে পারেন কী ভুল হচ্ছে।
- **Use Debugger**: আপনি Node.js এ ডিবাগিংয়ের জন্য `node inspect` ব্যবহার করতে পারেন অথবা Chrome DevTools এ ডিবাগ মোড চালু করতে পারেন।

---

## ⏸️ 5. Refactor Your Code

আপনার প্রোজেক্ট কোডের উন্নতি করার জন্য সময় দিন। প্রয়োজনীয় কোডগুলিকে ছোট, পরিষ্কার, এবং পুনঃব্যবহারযোগ্য করে তুলুন। উদাহরণস্বরূপ:
- **Helper Functions**: কিছু কোড পুনরায় ব্যবহারযোগ্য ফাংশনে ভাগ করুন।
- **Modularize Your Code**: যদি একাধিক ফাইল বা মডিউল ব্যবহার করা হয়, তাহলে আপনার কোডকে আরও সুসংগঠিত করতে পারেন।

---

## ⏸️ 6. Test Your API Endpoints

এখন আপনার তৈরি করা API এন্ডপয়েন্টগুলি Postman বা অন্য কোনো টুল ব্যবহার করে টেস্ট করুন। নিশ্চিত করুন যে:
1. **Valid Input**: সকল রিকোয়েস্ট সঠিকভাবে কাজ করছে।
2. **Invalid Input**: ভুল ইনপুট দেয়া হলে সঠিকভাবে error মেসেজ আসছে।
3. **Database Operations**: MongoDB বা অন্য ডাটাবেসে সঠিকভাবে ডেটা সেভ হচ্ছে এবং আসছে।

---

## 📌 In Short:

- **CRUD Operations**: নতুন অ্যাপ তৈরি করে পূর্ণ CRUD অপারেশন শিখা।
- **Error Handling**: বিভিন্ন প্রকারের ভুল এবং তাদের সমাধান শিখা।
- **Asynchronous Operations**: `async/await` এর ব্যবহার শিখা।
- **Debugging**: কোড ডিবাগিং শিখা।
- **Code Refactoring**: কোড পরিষ্কার এবং পুনঃব্যবহারযোগ্য করে তুলতে শিখা।
- **API Testing**: Postman বা অন্য টুল দিয়ে API টেস্টিং শিখা।

আজকের সেশনটি শেষ! পরবর্তী দিন থেকে আরও উন্নত ফিচার এবং প্রকল্প নিয়ে কাজ করা হবে। 🚀





# Day 21

✅ **আজকের দিনটি একটি Mini Project হবে।**  
আজকের লক্ষ্য হচ্ছে একটি `Product API` তৈরি করা যেখানে আমরা ডেটাবেস ব্যবহার না করে একটি in-memory array ব্যবহার করব ডেটা সংরক্ষণ এবং পরিচালনার জন্য। এটি একটি সিম্পল API হবে যা CRUD অপারেশন সমর্থন করবে।

---

## ⏸️ 1. Project Setup

প্রথমে, আপনার Node.js প্রোজেক্টটি সেট আপ করুন। `express` ইন্সটল করুন এবং একটি নতুন অ্যাপ্লিকেশন তৈরি করুন:

```bash
mkdir product-api
cd product-api
npm init -y
npm install express
```

এবং একটি `server.js` ফাইল তৈরি করুন।

```js
const express = require('express');
const app = express();
const port = 3000;

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
```

---

## ⏸️ 2. In-memory Product Array

এখন, একটি in-memory array তৈরি করুন, যেখানে আমরা পণ্যসমূহ সংরক্ষণ করব। প্রাথমিকভাবে এটি একটি সিম্পল অ্যারে হবে:

```js
const products = [
  { id: 1, name: 'Product 1', price: 100 },
  { id: 2, name: 'Product 2', price: 200 },
  { id: 3, name: 'Product 3', price: 300 }
];
```

---

## ⏸️ 3. Create API Routes

এখন, CRUD অপারেশনসমূহের জন্য API রাউট তৈরি করুন:

### 1. **GET all products**

এই রাউটটি সমস্ত পণ্যসমূহ ফিরিয়ে দেবে:

```js
app.get('/api/products', (req, res) => {
  res.json(products);
});
```

### 2. **GET single product by ID**

এই রাউটটি একটি নির্দিষ্ট `id` এর পণ্য ফিরিয়ে দেবে:

```js
app.get('/api/products/:id', (req, res) => {
  const product = products.find(p => p.id === parseInt(req.params.id));
  if (!product) return res.status(404).send('Product not found');
  res.json(product);
});
```

### 3. **POST create new product**

এই রাউটটি একটি নতুন পণ্য তৈরি করবে এবং in-memory array তে যোগ করবে:

```js
app.post('/api/products', (req, res) => {
  const { name, price } = req.body;
  const newProduct = {
    id: products.length + 1,
    name,
    price
  };
  products.push(newProduct);
  res.status(201).json(newProduct);
});
```

### 4. **PUT update product**

এই রাউটটি একটি নির্দিষ্ট পণ্য আপডেট করবে:

```js
app.put('/api/products/:id', (req, res) => {
  const product = products.find(p => p.id === parseInt(req.params.id));
  if (!product) return res.status(404).send('Product not found');
  
  const { name, price } = req.body;
  product.name = name || product.name;
  product.price = price || product.price;
  
  res.json(product);
});
```

### 5. **DELETE delete product**

এই রাউটটি একটি পণ্য মুছে ফেলবে:

```js
app.delete('/api/products/:id', (req, res) => {
  const productIndex = products.findIndex(p => p.id === parseInt(req.params.id));
  if (productIndex === -1) return res.status(404).send('Product not found');
  
  products.splice(productIndex, 1);
  res.status(204).send();
});
```

---

## ⏸️ 4. Middleware for JSON Parsing

কেননা আমরা `POST` এবং `PUT` রিকোয়েস্টে JSON ডেটা পাঠাচ্ছি, তাই `express.json()` middleware ব্যবহার করতে হবে:

```js
app.use(express.json());
```

---

## ⏸️ 5. Testing the API

এখন আপনি Postman বা অন্য কোন API টেস্টিং টুল ব্যবহার করে API রাউটগুলো টেস্ট করতে পারেন:

- **GET** `/api/products`: সমস্ত পণ্য পেতে।
- **GET** `/api/products/{id}`: একটি নির্দিষ্ট পণ্য পেতে।
- **POST** `/api/products`: নতুন পণ্য যোগ করতে।
- **PUT** `/api/products/{id}`: একটি পণ্য আপডেট করতে।
- **DELETE** `/api/products/{id}`: একটি পণ্য মুছে ফেলতে।

---

## ⏸️ 6. Code Refactor and Improvements

এখন আপনি কোডটি আরও পরিষ্কার এবং সুসংগঠিত করার জন্য পুনর্লিখন করতে পারেন:

- **Helper functions**: প্রয়োজনীয় কিছু কোডের জন্য হেল্পার ফাংশন তৈরি করুন।
- **Validation**: ইনপুট ভ্যালিডেশন যোগ করুন, যেমন নাম এবং দাম সঠিকভাবে রয়েছে কিনা।
- **Error handling**: আরও উন্নত error handling করুন।

---

## 📌 In Short:

- **In-memory data storage**: ডেটাবেস ছাড়াই ইন-মেমরি ডেটা স্টোরেজ ব্যবহার করা।
- **CRUD Operations**: পণ্য সম্পর্কিত CRUD অপারেশন তৈরি করা।
- **API Development**: API রাউট তৈরি করা এবং JSON ডেটা প্রেরণ এবং গ্রহণ করা।
- **Express Middleware**: Express এর `express.json()` middleware ব্যবহার করা।

আজকের মিনি প্রোজেক্টটি শেষ! পরবর্তী দিন থেকে আরও শক্তিশালী অ্যাপ্লিকেশন তৈরি করা হবে। 🚀


