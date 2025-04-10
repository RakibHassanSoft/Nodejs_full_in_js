
# Day 1

✅ **প্রথমে আপনার কম্পিউটারে Node.js ইন্সটল করুন।**  
Node.js হলো একটি জাভাস্ক্রিপ্ট রানটাইম এনভায়রনমেন্ট, যা ব্রাউজারের বাইরে জাভাস্ক্রিপ্ট কোড রান করতে সাহায্য করে।  
Node.js ইন্সটল করার জন্য অফিসিয়াল ওয়েবসাইটে যান: https://nodejs.org  
সেখানে আপনার অপারেটিং সিস্টেম অনুযায়ী LTS (Long Term Support) ভার্সনটি ডাউনলোড করুন ও ইন্সটল করুন।

✅ **Node.js ইন্সটল করলে সাথে npm (Node Package Manager) স্বয়ংক্রিয়ভাবে ইন্সটল হয়ে যাবে।**  
npm ব্যবহার করে আপনি বিভিন্ন প্যাকেজ বা লাইব্রেরি ইন্সটল করতে পারবেন, যা আপনার প্রজেক্টে দরকার হতে পারে।

✅ **এখন yarn ইন্সটল করুন (একটি বিকল্প প্যাকেজ ম্যানেজার)।**  
Yarn আরও ফাস্ট এবং রিলায়েবল প্যাকেজ ম্যানেজমেন্ট সিস্টেম হিসেবে কাজ করে।  
Yarn ইন্সটল করতে টার্মিনালে নিচের কমান্ডটি দিন:

npm install --global yarn

অথবা অফিসিয়াল ইনস্টলেশন গাইড দেখুন: https://classic.yarnpkg.com/lang/en/docs/install/

✅ **এখন একটি নতুন জাভাস্ক্রিপ্ট ফাইল তৈরি করুন।**  
একটি ফোল্ডার তৈরি করুন, যেমন: my-first-js-project  
এরপর সেই ফোল্ডারের ভিতরে একটি `.js` ফাইল তৈরি করুন, যেমন: index.js

✅ **index.js ফাইলের ভিতরে নিচের কোডটি লিখুন:**

console.log("Hello, World!");

✅ **এখন টার্মিনালে ফাইলটি রান করুন।**  
টার্মিনালে আপনার ফোল্ডারে যান:

cd my-first-js-project

এরপর কমান্ডটি চালান:

node index.js

🎉 আপনি যদি "Hello, World!" আউটপুট পান, তাহলে আপনি সফলভাবে আপনার প্রথম জাভাস্ক্রিপ্ট কোড Node.js দিয়ে রান করাতে পেরেছেন।





# Day 2

✅ **আজ আমরা Node.js এর কিছু Core Modules শিখবো:**  
এই মডিউলগুলো Node.js এর বিল্ট-ইন, তাই এগুলো ব্যবহার করতে আলাদা করে ইন্সটল করার দরকার নেই।

---

## 📁 1. `fs` (File System)

`fs` মডিউল ফাইল তৈরি, পড়া, লেখা, মুছে ফেলা ইত্যাদি কাজের জন্য ব্যবহৃত হয়।

```js
const fs = require('fs');

// একটি ফাইল তৈরি ও লেখার উদাহরণ
fs.writeFileSync('demo.txt', 'Hello from fs module!');

// ফাইল পড়ার উদাহরণ
const data = fs.readFileSync('demo.txt', 'utf-8');
console.log(data);
```

---

## 📂 2. `path` (Path Utilities)

`path` মডিউল ফাইল ও ডিরেক্টরির পাথ ম্যানিপুলেশনের জন্য ব্যবহৃত হয়।

```js
const path = require('path');

const filePath = path.join(__dirname, 'folder', 'file.txt');
console.log('File Path:', filePath);

console.log('Extension:', path.extname(filePath));
```

---

## 🖥 3. `os` (Operating System Info)

`os` মডিউল দিয়ে আপনি অপারেটিং সিস্টেম সংক্রান্ত তথ্য পেতে পারেন।

```js
const os = require('os');

console.log('OS Type:', os.type());
console.log('Total Memory:', os.totalmem());
console.log('Free Memory:', os.freemem());
console.log('User Info:', os.userInfo());
```

---

## 🎉 4. `events` (EventEmitter)

`events` মডিউল দিয়ে আপনি নিজের কাস্টম ইভেন্ট তৈরি করতে পারবেন।

```js
const EventEmitter = require('events');
const myEmitter = new EventEmitter();

myEmitter.on('greet', () => {
  console.log('Hello from event emitter!');
});

myEmitter.emit('greet');
```





# Day 3

✅ **আজ আমরা শিখবো `require` ও `import` এর পার্থক্য এবং কিভাবে মডিউল এক্সপোর্ট ও ইমপোর্ট করতে হয়।**

Node.js এ দুটি উপায়ে মডিউল ইমপোর্ট ও এক্সপোর্ট করা যায়:

---

## 🧩 1. `require()` — CommonJS (পুরাতন স্টাইল)

Node.js ডিফল্টভাবে CommonJS ব্যবহার করে। এখানে আপনি `require()` এবং `module.exports` ব্যবহার করেন।

### 👉 একটি ফাইল `math.js`

```js
// math.js
function add(a, b) {
  return a + b;
}

function subtract(a, b) {
  return a - b;
}

module.exports = { add, subtract };
```

### 👉 আরেকটি ফাইল `app.js`

```js
// app.js
const math = require('./math');

console.log(math.add(5, 3));        // Output: 8
console.log(math.subtract(10, 4));  // Output: 6
```

---

## 🧩 2. `import` — ES Modules (আধুনিক স্টাইল)

এই স্টাইলটি ব্যবহার করতে হলে আপনাকে `package.json` ফাইলে `"type": "module"` যুক্ত করতে হবে।

### 👉 একটি ফাইল `math.js`

```js
// math.js
export function add(a, b) {
  return a + b;
}

export function subtract(a, b) {
  return a - b;
}
```

### 👉 আরেকটি ফাইল `app.js`

```js
// app.js
import { add, subtract } from './math.js';

console.log(add(5, 3));        // Output: 8
console.log(subtract(10, 4));  // Output: 6
```

✅ আপনি যদি `default export` করতে চান:

```js
// math.js
export default function multiply(a, b) {
  return a * b;
}
```

```js
// app.js
import multiply from './math.js';

console.log(multiply(4, 5)); // Output: 20
```





# Day 4

✅ **আজ আমরা শিখবো কিভাবে আমাদের নিজের মডিউল সিস্টেম তৈরি করতে হয়।**  
মডিউল সিস্টেম তৈরি করার মাধ্যমে আপনি আপনার কোডকে আরও পরিষ্কার এবং পুণঃব্যবহারযোগ্য করতে পারবেন।

---

## 📦 1. মডিউল তৈরি করা

প্রথমে, একটি নতুন ফোল্ডার তৈরি করুন এবং সেখানে দুটি ফাইল রাখুন। একটিতে আপনার মডিউল কোড থাকবে এবং অন্যটিতে সেটি ইমপোর্ট করা হবে।

ধরি, আমরা একটি মডিউল তৈরি করছি যা সংখ্যা গুণ করার কাজ করবে।

### 👉 ফাইল `math.js`

```js
// math.js

// গুণফল বের করার ফাংশন
function multiply(a, b) {
  return a * b;
}

// আমাদের মডিউল এক্সপোর্ট করা
module.exports = multiply;
```

---

## 📦 2. মডিউল ব্যবহার করা

এখন আমরা `math.js` মডিউলটিকে অন্য একটি ফাইলে ব্যবহার করবো।

### 👉 ফাইল `app.js`

```js
// app.js

// math.js মডিউল ইমপোর্ট করা
const multiply = require('./math');

// গুণফল বের করা
console.log(multiply(5, 6));  // Output: 30
```

এভাবে আপনি আপনার কোডকে মডিউল হিসেবে ভাগ করে কাজ করতে পারবেন, যা অন্য কোথাও ইমপোর্ট করা সম্ভব।

---

## 📦 3. বিভিন্ন মডিউল তৈরি করা

আপনি বিভিন্ন ধরনের ফাংশন একাধিক মডিউলে রাখতে পারেন। উদাহরণস্বরূপ, গুন, ভাগ এবং যোগফল বের করার আলাদা আলাদা মডিউল তৈরি করা যাক।

### 👉 ফাইল `multiply.js`

```js
// multiply.js
function multiply(a, b) {
  return a * b;
}

module.exports = multiply;
```

### 👉 ফাইল `divide.js`

```js
// divide.js
function divide(a, b) {
  if (b === 0) {
    return 'Error: Division by zero';
  }
  return a / b;
}

module.exports = divide;
```

### 👉 ফাইল `app.js`

```js
// app.js
const multiply = require('./multiply');
const divide = require('./divide');

console.log(multiply(10, 2));  // Output: 20
console.log(divide(10, 2));    // Output: 5
console.log(divide(10, 0));    // Output: Error: Division by zero
```





# Day 5

✅ **আজ আমরা শিখবো কিভাবে Node.js এর `http` মডিউল ব্যবহার করে একটি বেসিক সার্ভার সেটআপ করতে হয়।**  
Node.js এর `http` মডিউল ব্যবহার করে আমরা খুব সহজে একটি HTTP সার্ভার তৈরি করতে পারি, যা ক্লায়েন্ট রিকুয়েস্ট গ্রহণ করতে এবং রেসপন্স পাঠাতে সক্ষম।

---

## 📡 1. `http` মডিউল ইমপোর্ট করা

প্রথমে `http` মডিউলটি ইমপোর্ট করুন এবং একটি সার্ভার তৈরি করুন।

### 👉 ফাইল `server.js`

```js
// http মডিউল ইমপোর্ট করা
const http = require('http');

// সার্ভার তৈরি করা
const server = http.createServer((req, res) => {
  // রেসপন্স হেডার সেট করা
  res.writeHead(200, { 'Content-Type': 'text/plain' });

  // রেসপন্স পাঠানো
  res.end('Hello, World! Welcome to Node.js Server.');
});

// সার্ভারটি লিসেন করছে পোর্ট 3000 এ
server.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});
```

---

## 📡 2. সার্ভার চালানো

এই কোডটি রান করার জন্য টার্মিনালে `node server.js` কমান্ডটি দিন।

```bash
node server.js
```

এখন আপনার সার্ভারটি পোর্ট 3000 এ রান করবে। আপনি আপনার ব্রাউজারে `http://localhost:3000` লিখে আপনার সার্ভারটি দেখতে পারবেন। আপনি "Hello, World! Welcome to Node.js Server." বার্তাটি দেখবেন।

---

## 📡 3. HTTP রিকুয়েস্ট ও রেসপন্স

আপনি `req` (রিকুয়েস্ট) এবং `res` (রেসপন্স) অবজেক্ট ব্যবহার করে ক্লায়েন্টের রিকুয়েস্ট অনুযায়ী সার্ভারকে রেসপন্স পাঠাতে পারবেন। উদাহরণস্বরূপ, আমরা একটি GET রিকুয়েস্ট হ্যান্ডেল করতে পারি।

```js
// GET রিকুয়েস্ট হ্যান্ডেল করা
const server = http.createServer((req, res) => {
  if (req.method === 'GET' && req.url === '/') {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Welcome to the GET route!');
  } else {
    res.writeHead(404, { 'Content-Type': 'text/plain' });
    res.end('Page Not Found');
  }
});

server.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});
```

এখন, যদি আপনি `http://localhost:3000` ব্রাউজারে যান, আপনি "Welcome to the GET route!" বার্তা পাবেন। অন্য কোন রিকুয়েস্ট পাঠালে 404 "Page Not Found" রেসপন্স পাবেন।






# Day 6

✅ **আজ আমরা একটি সাধারন সার্ভার তৈরি করবো, যা JSON রেসপন্স ফিরিয়ে দিবে।**  
এই প্র্যাকটিস এক্সারসাইজে, আমরা HTTP সার্ভারের মাধ্যমে একটি JSON ডেটা রিটার্ন করতে শিখবো।

---

## 🖥 1. HTTP সার্ভার তৈরি করা

প্রথমে একটি HTTP সার্ভার তৈরি করি যা ক্লায়েন্টের রিকুয়েস্টে JSON ডেটা রিটার্ন করবে।

### 👉 ফাইল `server.js`

```js
// http মডিউল ইমপোর্ট করা
const http = require('http');

// সার্ভার তৈরি করা
const server = http.createServer((req, res) => {
  // রিকুয়েস্টের URL চেক করা
  if (req.method === 'GET' && req.url === '/data') {
    // রেসপন্স হেডার সেট করা
    res.writeHead(200, { 'Content-Type': 'application/json' });

    // JSON ডেটা রিটার্ন করা
    const data = {
      message: 'Hello, this is your JSON response!',
      status: 'success',
      code: 200
    };

    // JSON ডেটা পাঠানো
    res.end(JSON.stringify(data));
  } else {
    // অন্য রিকুয়েস্টের জন্য 404 রেসপন্স
    res.writeHead(404, { 'Content-Type': 'text/plain' });
    res.end('Page Not Found');
  }
});

// সার্ভারটি পোর্ট 3000 এ চালানো
server.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});
```

---

## 🖥 2. সার্ভার চালানো

এই কোডটি রান করতে, টার্মিনালে `node server.js` কমান্ড দিন।

```bash
node server.js
```

এখন আপনার সার্ভারটি পোর্ট 3000 এ রান করবে। আপনি ব্রাউজারে `http://localhost:3000/data` এ গিয়ে JSON রেসপন্স দেখতে পারবেন:

```json
{
  "message": "Hello, this is your JSON response!",
  "status": "success",
  "code": 200
}
```





# Day 7


✅ **আজ আমরা সাপ্তাহিক পর্যালোচনা এবং একটি ছোট প্রকল্প তৈরি করবো, যা একটি স্ট্যাটিক ফাইল সার্ভার হবে।**

আজকের কাজ হবে সমস্ত শিখা বিষয়গুলো একত্রিত করা এবং একটি সাধারণ স্ট্যাটিক ফাইল সার্ভার তৈরি করা, যা আমাদের HTML, CSS এবং JavaScript ফাইলগুলি সরবরাহ করবে।

---

## 🗂 1. সাপ্তাহিক পর্যালোচনা

এখন পর্যন্ত আমরা শিখেছি:

- **Node.js মডিউল সিস্টেম:** আমরা শিখেছি কিভাবে মডিউল তৈরি, এক্সপোর্ট এবং ইমপোর্ট করতে হয়।  
- **HTTP সার্ভার:** আমরা HTTP সার্ভার তৈরি করে রিকুয়েস্ট এবং রেসপন্স হ্যান্ডেল করতে শিখেছি।  
- **JSON রেসপন্স:** আমরা একটি সার্ভার তৈরি করেছি যা JSON ডেটা রিটার্ন করে।  
- **`require` vs `import`:** আমরা শিখেছি কিভাবে CommonJS এবং ES Modules ব্যবহার করা হয়।

---

## 🖥 2. Mini Project: Static File Server

এখন আমরা একটি ছোট প্রজেক্ট তৈরি করবো, যেখানে একটি HTTP সার্ভার তৈরি করা হবে যা স্ট্যাটিক ফাইল সার্ভ করবে। আমরা HTML, CSS এবং JavaScript ফাইল সরবরাহ করতে পারবো।

### 👉 ফাইল `server.js`

```js
// http এবং fs মডিউল ইমপোর্ট করা
const http = require('http');
const fs = require('fs');
const path = require('path');

// সার্ভার তৈরি করা
const server = http.createServer((req, res) => {
  let filePath = '.' + req.url;

  if (filePath == './') {
    filePath = './index.html';  // যদি রুট URL হয়, index.html দেখানো হবে
  }

  // ফাইল এক্সটেনশন বের করা
  const extname = String(path.extname(filePath)).toLowerCase();
  
  // ফাইল টাইপ অনুযায়ী কন্টেন্ট-টাইপ সেট করা
  let contentType = 'text/html';
  switch (extname) {
    case '.js':
      contentType = 'application/javascript';
      break;
    case '.css':
      contentType = 'text/css';
      break;
    case '.json':
      contentType = 'application/json';
      break;
    case '.png':
      contentType = 'image/png';
      break;
    case '.jpg':
      contentType = 'image/jpg';
      break;
    case '.gif':
      contentType = 'image/gif';
      break;
  }

  // ফাইল রিড করা এবং রেসপন্স পাঠানো
  fs.readFile(filePath, (err, content) => {
    if (err) {
      res.writeHead(500);
      res.end('Sorry, an error occurred: ' + err.code);
      return;
    }
    res.writeHead(200, { 'Content-Type': contentType });
    res.end(content, 'utf-8');
  });
});

// সার্ভার পোর্ট 3000 এ চালানো
server.listen(3000, () => {
  console.log('Server running at http://localhost:3000/');
});
```

---

### 👉 ফাইল `index.html`

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Static File Server</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <h1>Welcome to the Static File Server</h1>
  <p>This page is being served using Node.js!</p>
  <script src="script.js"></script>
</body>
</html>
```

---

### 👉 ফাইল `style.css`

```css
body {
  font-family: Arial, sans-serif;
  text-align: center;
  background-color: #f4f4f4;
  color: #333;
}

h1 {
  color: #4CAF50;
}
```

---

### 👉 ফাইল `script.js`

```js
console.log('JavaScript file is successfully loaded!');
```

---

## 🖥 3. সার্ভার চালানো

এই কোডটি রান করতে, টার্মিনালে `node server.js` কমান্ড দিন।

```bash
node server.js
```

এখন আপনার সার্ভারটি পোর্ট 3000 এ রান করবে। আপনি ব্রাউজারে `http://localhost:3000` এ গিয়ে আপনার HTML পেজ দেখতে পারবেন। সমস্ত স্ট্যাটিক ফাইল (HTML, CSS, JS) সার্ভ করা হবে।

---

## 📌 In short:

- **সাপ্তাহিক পর্যালোচনা:** আমরা এখন পর্যন্ত শিখা বিষয়গুলো রিভিউ করলাম।  
- **স্ট্যাটিক ফাইল সার্ভার:** কিভাবে একটি HTTP সার্ভার তৈরি করা যায় যা HTML, CSS এবং JavaScript ফাইল সার্ভ করবে।  
- **কন্টেন্ট টাইপ:** স্ট্যাটিক ফাইলের কন্টেন্ট টাইপ নির্ধারণ করে সঠিক ফাইল রিটার্ন করা।

এখন আপনি স্ট্যাটিক ফাইল সার্ভ করতে শিখেছেন এবং Node.js দিয়ে একটি ছোট প্রজেক্ট তৈরি করেছেন!
```




