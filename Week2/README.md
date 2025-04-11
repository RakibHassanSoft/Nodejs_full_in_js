# Day 8

✅ **আজ আমরা Callbacks এবং Promises সম্পর্কে শিখবো।**  
Node.js এ Asynchronous কাজ করার জন্য আমরা Callbacks এবং Promises ব্যবহার করি। আজকের সেশনে আমরা জানবো কিভাবে Callbacks এবং Promises কাজ করে এবং কীভাবে এইগুলো ব্যবহার করতে হয়।

---

## 📞 1. Callbacks

Callbacks হলো একটি ফাংশন যা আরেকটি ফাংশনকে আর্গুমেন্ট হিসেবে পাস করা হয় এবং সেই ফাংশনটি তার কাজ শেষ হলে কল করা হয়।

### 👉 উদাহরণ: Callback ব্যবহার

```js
// একটি ফাংশন যা সময় নেয় এবং পরে কলব্যাক ফাংশনটি কল করে
function fetchData(callback) {
  setTimeout(() => {
    console.log('Data fetched!');
    callback('Data is ready');  // কলব্যাক ফাংশন কল করা
  }, 2000);
}

// কলব্যাক ফাংশন পাস করা
fetchData((message) => {
  console.log(message);  // 'Data is ready' মেসেজটি দেখাবে
});
```

এই কোডে, `fetchData` ফাংশনটি ডেটা ফেচ করার পর কলব্যাক ফাংশনটিকে কল করবে।

---

## 🌟 2. Promises

Promises হলো একটি উন্নত ধারণা যা কলব্যাকের তুলনায় বেশি পরিষ্কার এবং পরিচালনা করা সহজ। এটি একটি অস্থায়ী মান প্রদান করে যা ভবিষ্যতে রিটার্ন হবে। Promise এর দুটি অবস্থা রয়েছে: **resolved** (fulfilled) এবং **rejected**।

### 👉 উদাহরণ: Promise ব্যবহার

```js
// একটি ফাংশন যা Promise রিটার্ন করে
function fetchData() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log('Data fetched!');
      resolve('Data is ready');  // Promise resolve করা
    }, 2000);
  });
}

// Promise ব্যবহার করা
fetchData()
  .then((message) => {
    console.log(message);  // 'Data is ready' মেসেজটি দেখাবে
  })
  .catch((error) => {
    console.log(error);  // কোনো ত্রুটি হলে দেখাবে
  });
```

এখানে, `fetchData` ফাংশন একটি Promise রিটার্ন করছে যা নির্দিষ্ট সময় পরে **resolved** হয় এবং `then` মেথডের মাধ্যমে আমরা সফল রেসপন্স পেতে পারি। যদি কোনো সমস্যা ঘটে, তাহলে `catch` মেথড ব্যবহার করে তা ধরতে পারি।

---

## 📚 3. Callbacks vs Promises

| Callbacks                          | Promises                                 |
|-------------------------------------|------------------------------------------|
| একটি ফাংশনকে আর্গুমেন্ট হিসেবে পাস করা হয় | Promise অবজেক্ট রিটার্ন করা হয়         |
| কোডের উন্নত প্রবাহ তৈরি করা কঠিন হতে পারে | Promise চেইনিং সুবিধা দেয়              |
| Callback Hell বা Pyramid of Doom তৈরি হতে পারে | সহজে error handling সম্ভব            |

Promises ব্যবহার করা বেশি সুবিধাজনক কারণ এটি কোডের পরিচালনযোগ্যতা বাড়ায় এবং কোডের প্রবাহ পরিষ্কার রাখে।

---

## 📌 In Short:

- **Callbacks:** একটি ফাংশনকে অন্য ফাংশনে আর্গুমেন্ট হিসেবে পাস করা এবং এটি পরে কল করা।  
- **Promises:** একটি অস্থায়ী মান রিটার্ন করে যা ভবিষ্যতে রিটার্ন হবে, এবং কিভাবে এটি `then` এবং `catch` ব্যবহার করে হ্যান্ডেল করা যায়।  
- **Callbacks vs Promises:** কলব্যাক ও প্রমিজের মধ্যে পার্থক্য এবং তাদের ব্যবহারের সুবিধা।

এখন আপনি Callbacks এবং Promises এর মধ্যে পার্থক্য বুঝতে পারবেন এবং এগুলোর সাথে কাজ করতে পারবেন!





# Day 9

✅ **আজ আমরা Async/Await এবং Error Handling শিখবো।**  
Async/Await হলো Promises এর একটি আরও সহজ এবং কার্যকরী উপায় যা অ্যাসিঙ্ক্রোনাস কোড লেখা সহজ করে। আজকের সেশনে আমরা জানবো কিভাবে Async/Await কাজ করে এবং কিভাবে এর মাধ্যমে Error Handling করতে হয়।

---

## 📝 1. Async/Await

Async/Await হলো JavaScript এর একটি নতুন বৈশিষ্ট্য যা Promises এর উপর ভিত্তি করে কাজ করে এবং কোডের রিডেবিলিটি এবং ব্যাখ্যাযোগ্যতা বাড়ায়। `async` কিওয়ার্ড ব্যবহার করে একটি ফাংশনকে অ্যাসিঙ্ক্রোনাস ফাংশন হিসেবে চিহ্নিত করা হয় এবং `await` কিওয়ার্ড ব্যবহার করে Promises এর রেজাল্ট পাওয়া যায়।

### 👉 উদাহরণ: Async/Await ব্যবহার

```js
// Async ফাংশন তৈরি করা
async function fetchData() {
  // Await ব্যবহার করে Promise এর রেজাল্ট পাওয়া
  let result = await new Promise((resolve) => {
    setTimeout(() => {
      resolve('Data is ready!');
    }, 2000);
  });
  console.log(result);  // 'Data is ready!' মেসেজটি দেখাবে
}

fetchData();
```

এই উদাহরণে, `fetchData` ফাংশনটি `async` কিওয়ার্ড দ্বারা অ্যাসিঙ্ক্রোনাস করা হয়েছে এবং `await` এর মাধ্যমে Promise এর রেজাল্ট পাওয়া হচ্ছে। `await` কিওয়ার্ডটি Promise সম্পূর্ণ হওয়ার আগে পরবর্তী লাইন এক্সিকিউট হতে দেবে না।

---

## ⚠️ 2. Error Handling with Async/Await

Async/Await এর সাথে আমরা সাধারণত `try...catch` ব্লক ব্যবহার করে ত্রুটি হ্যান্ডেল করি। এটি Promise এর `catch` মেথডের মতই কাজ করে, কিন্তু কোডের আরও পরিষ্কার এবং পাঠযোগ্য রূপ প্রদান করে।

### 👉 উদাহরণ: Error Handling with Async/Await

```js
// Async ফাংশন তৈরি করা
async function fetchData() {
  try {
    // একটি ভুল Promise যা reject করবে
    let result = await new Promise((resolve, reject) => {
      setTimeout(() => {
        reject('Something went wrong!');
      }, 2000);
    });
    console.log(result);  // এই লাইনটি এক্সিকিউট হবে না
  } catch (error) {
    // ত্রুটি ধরার জন্য catch ব্লক
    console.log(error);  // 'Something went wrong!' মেসেজটি দেখাবে
  }
}

fetchData();
```

এখানে, আমরা একটি `try...catch` ব্লক ব্যবহার করেছি যাতে যদি কোনো ত্রুটি ঘটে, তাহলে তা ধরতে এবং হ্যান্ডেল করতে পারি। `await` এর মাধ্যমে `Promise.reject` হলে সেই ত্রুটিটি `catch` ব্লকে ধরা হবে।

---

## 📌 In short:

- **Async/Await:** কিভাবে `async` এবং `await` ব্যবহার করে অ্যাসিঙ্ক্রোনাস কোড লেখা যায় এবং Promises এর সাথে কাজ করা যায়।  
- **Error Handling:** কিভাবে `try...catch` ব্লক ব্যবহার করে Async/Await এর সাথে ত্রুটি হ্যান্ডেল করা যায়।

এখন আপনি Async/Await এবং Error Handling সম্পর্কে সম্পূর্ণ ধারণা পেয়েছেন এবং এটি আপনার কোডের কার্যকারিতা এবং পরিষ্কারতা আরও বাড়াবে!




# Day 10

✅ **আজ আমরা Event Loop এবং Call Stack সম্পর্কে শিখবো।**  
JavaScript এ অ্যাসিঙ্ক্রোনাস কোড কিভাবে কাজ করে এবং বিভিন্ন ফাংশন কিভাবে এক্সিকিউট হয়, তা বুঝতে Event Loop এবং Call Stack এর ভূমিকা খুব গুরুত্বপূর্ণ। আজকের সেশনে আমরা এদের কার্যপ্রণালী বিস্তারিতভাবে জানবো।

---

## 🔄 1. Call Stack

Call Stack হলো একটি ডেটা স্ট্রাকচার যা বর্তমান এক্সিকিউট হচ্ছে এমন ফাংশনগুলোকে ট্র্যাক করে। যখন একটি ফাংশন কল করা হয়, সেটি Call Stack এ push হয়। ফাংশনটি সম্পন্ন হলে, সেটি Call Stack থেকে pop হয়ে যায়।

### 👉 উদাহরণ: Call Stack

```js
function first() {
  console.log('First function');
  second();
}

function second() {
  console.log('Second function');
}

first();
```

এখানে, `first()` ফাংশন কল করার পরে, `second()` ফাংশনও কল হবে। এগুলো Call Stack এ একে একে push হবে এবং সম্পন্ন হলে pop হয়ে যাবে।

### Call Stack এর কার্যপ্রণালী:

1. `first()` কল করা হয় এবং Call Stack এ push হয়।
2. `first()` এর ভিতর `second()` কল করা হয় এবং এটি Call Stack এ push হয়।
3. `second()` সম্পন্ন হলে এটি Call Stack থেকে pop হয়ে যায়।
4. `first()` সম্পন্ন হলে এটি Call Stack থেকে pop হয়ে যায়।

---

## 🔄 2. Event Loop

Event Loop হলো একটি মেকানিজম যা JavaScript কে অ্যাসিঙ্ক্রোনাস কোড পরিচালনা করতে সাহায্য করে। JavaScript একসাথে একাধিক কাজ করতে পারে না (single-threaded), তবে Event Loop এর মাধ্যমে সেটি একাধিক কাজের মধ্যে সুইচ করতে সক্ষম হয়।

Event Loop JavaScript এর Call Stack এবং Callback Queue এর মধ্যে সমন্বয় করে কাজ করে। যখন Call Stack খালি হয়, তখন Event Loop Callback Queue থেকে কাজ নিয়ে Call Stack এ প্রক্রিয়া শুরু করে।

### 👉 উদাহরণ: Event Loop

```js
console.log('Start');

setTimeout(() => {
  console.log('Timeout');
}, 2000);

console.log('End');
```

এই কোডে:

1. প্রথমে `console.log('Start')` Call Stack এ চলে আসে এবং কনসোল লগ হয়।
2. এরপর `setTimeout` কল করা হয়, যা 2000 মিলিসেকেন্ড পরে একটি কলব্যাক ফাংশন রান করবে। `setTimeout` এর কলব্যাকটি Event Queue তে পুশ হয়।
3. পরবর্তী `console.log('End')` Call Stack এ চলে আসে এবং কনসোল লগ হয়।
4. 2000 মিলিসেকেন্ড পরে Event Loop Callback Queue থেকে `setTimeout` এর কলব্যাক নিয়ে Call Stack এ পুশ করে এবং তা কনসোল লগ হয়।

### Call Stack, Callback Queue, এবং Event Loop এর সম্পর্ক:

- **Call Stack**: যেখান থেকে ফাংশনগুলো রান হয়।  
- **Callback Queue**: অ্যাসিঙ্ক্রোনাস কাজ যেমন `setTimeout`, `setInterval` থেকে কলব্যাক ফাংশনগুলো এখানে যায়।  
- **Event Loop**: Call Stack খালি হলে, Callback Queue থেকে ফাংশন নিয়ে Call Stack এ চালানো হয়।

---

## 📌 In Short:

- **Call Stack:** এটি ফাংশন কলের ট্র্যাক রাখে এবং এক্সিকিউটেড ফাংশনগুলো পপ ও পুশ করে।  
- **Event Loop:** এটি অ্যাসিঙ্ক্রোনাস কোড রান করার জন্য Call Stack এবং Callback Queue এর মধ্যে সমন্বয় করে কাজ করে।

এখন আপনি JavaScript এর Event Loop এবং Call Stack এর কার্যপ্রণালী বুঝতে পারবেন, যা অ্যাসিঙ্ক্রোনাস কোড এক্সিকিউশন বুঝতে সাহায্য করবে!





# Day 11

✅ **আজ আমরা Debouncing এবং Throttling শিখবো।**  
Debouncing এবং Throttling হলো দুটি টেকনিক যা আমরা JavaScript এ ইভেন্ট হ্যান্ডলিংয়ের ক্ষেত্রে ব্যবহার করি, বিশেষ করে যখন আমাদের অনেক বেশি ইভেন্ট ফায়ার করা হয়, যেমন স্ক্রলিং, টাইপিং ইত্যাদি। এই টেকনিকগুলোর মাধ্যমে আমরা আমাদের কোডকে আরও কার্যকর এবং পারফরম্যান্স অপটিমাইজ করতে পারি। আজকের সেশনে আমরা শিখবো কিভাবে Debouncing এবং Throttling কাজ করে এবং কিভাবে এগুলো ব্যবহার করা হয়।

---

## ⏸️ 1. Debouncing

Debouncing হলো একটি কৌশল যা ইভেন্টের ফায়ারিংকে নির্দিষ্ট সময়ের জন্য বিলম্বিত করে, যেন একই ইভেন্ট বারবার না ঘটে। এটি বিশেষত তখন ব্যবহৃত হয় যখন একটি ইভেন্ট দ্রুত বারবার ফায়ার হচ্ছে, যেমন `input` ফিল্ডে টাইপ করা বা স্ক্রল করা। উদাহরণস্বরূপ, যখন আপনি একটি সার্চ বক্সে টাইপ করেন, প্রতিটি টাইপের পরে সার্চ ফাংশনটি কল করা দরকার না। আমরা Debouncing ব্যবহার করি যাতে সার্চ ফাংশনটি শুধু তখন কল হয় যখন টাইপিং শেষ হয় এবং ব্যবহারকারী আর নতুন কিছু টাইপ করছেন না।

### 👉 উদাহরণ: Debouncing

```js
// Debouncing ফাংশন তৈরি
function debounce(func, delay) {
  let timeout;
  return function(...args) {
    clearTimeout(timeout);  // পূর্বের timeout পরিষ্কার করা
    timeout = setTimeout(() => {
      func(...args);  // ফাংশনটি নির্দিষ্ট বিলম্ব পরে কল করা
    }, delay);
  };
}

// সার্চ ফাংশন
function search(query) {
  console.log('Searching for:', query);
}

// Debounce করা ফাংশন
const debouncedSearch = debounce(search, 1000);

// টাইপ করার সময় Debounced ফাংশন কল করা
document.getElementById('search').addEventListener('input', (event) => {
  debouncedSearch(event.target.value);
});
```

### **কীভাবে কাজ করে Debouncing?**
- যখন আপনি টাইপ করতে শুরু করেন, `input` ইভেন্টটি বারবার ফায়ার হতে থাকে।
- যদি ব্যবহারকারী দ্রুত টাইপ করে, প্রতিটি টাইপের পরে `search` ফাংশন কল করা হবে না। পরিবর্তে, `debounce` ফাংশনটি একটি নতুন টাইমআউট সেট করে এবং পূর্ববর্তী টাইমআউটকে পরিষ্কার করে, অর্থাৎ, যদি ব্যবহারকারী আরও টাইপ করেন, আগের কলটি বাতিল হয়ে যাবে এবং শুধুমাত্র টাইপিং শেষ হলে ফাংশনটি কল হবে।
- এতে করে সার্ভার থেকে অতিরিক্ত রিকোয়েস্ট পাঠানো বা অপ্রয়োজনীয় কাজের চাপ কমে যাবে।

---

## 🚦 2. Throttling

Throttling হলো একটি কৌশল যা একটি নির্দিষ্ট সময়ের মধ্যে একাধিক ইভেন্ট ফায়ার করার পরিবর্তে, ইভেন্টটিকে একটি নির্দিষ্ট সময়ের পরে চালায়। এর মানে হল যে, একটি নির্দিষ্ট সময়ের মধ্যে কেবল একবার ফাংশন কল হবে, সে যাই হোক না কেন। এটি বিশেষভাবে দরকারি যখন ইভেন্টগুলো খুব দ্রুত ঘটছে, যেমন স্ক্রলিং বা রিসাইজ ইভেন্ট। সাধারণত, থ্রটলিং ব্যবহৃত হয় যাতে বারবার ফাংশন কল না হয়, যা পারফরম্যান্সের ক্ষতি করতে পারে।

### 👉 উদাহরণ: Throttling

```js
// Throttling ফাংশন তৈরি
function throttle(func, limit) {
  let lastFunc;
  let lastRan;
  return function() {
    const context = this;
    const args = arguments;
    if (!lastRan) {
      func.apply(context, args);  // প্রথমবারেই ফাংশন কল
      lastRan = Date.now();
    } else {
      clearTimeout(lastFunc);  // পূর্বের timeout পরিষ্কার করা
      lastFunc = setTimeout(function() {
        if (Date.now() - lastRan >= limit) {
          func.apply(context, args);  // নির্দিষ্ট সময় পর ফাংশন কল
          lastRan = Date.now();
        }
      }, limit - (Date.now() - lastRan));
    }
  };
}

// স্ক্রল ফাংশন
function logScroll() {
  console.log('Scroll event fired!');
}

// Throttled স্ক্রল ফাংশন
const throttledScroll = throttle(logScroll, 2000);

// স্ক্রল ইভেন্টে Throttled ফাংশন কল করা
window.addEventListener('scroll', throttledScroll);
```

### **কীভাবে কাজ করে Throttling?**
- স্ক্রল ইভেন্টটি যদি দ্রুত ঘটে (যেমন একের পর এক স্ক্রল করা), থ্রটলিং নিশ্চিত করে যে, এটি প্রতি 2000 মিলিসেকেন্ড (2 সেকেন্ড) অন্তর একবারই কল হবে।
- অর্থাৎ, থ্রটলিং ফাংশনটি একবার কল হওয়ার পর, পরবর্তী কলটি আসতে অন্তত 2 সেকেন্ড অপেক্ষা করবে।
- এতে করে স্ক্রল ইভেন্টে খুব কম ফাংশন কল হয় এবং পারফরম্যান্সে ক্ষতি হয় না।

---

## 📌 In Short:

- **Debouncing:** এটি একটি কৌশল যা ইভেন্ট ফায়ারিংকে বিলম্বিত করে, যেমন টাইপিং বা সার্চ বক্সে ইনপুট দেওয়ার সময়। এটি প্রতিটি ইভেন্টের পরে ফাংশন কল না করে, একবার টাইপিং শেষ হলে ফাংশন কল করে।  
- **Throttling:** এটি একটি কৌশল যা নির্দিষ্ট সময় অন্তর ইভেন্ট ফায়ারিং রেট সীমাবদ্ধ করে, যেমন স্ক্রলিং বা রিসাইজ ইভেন্টের ক্ষেত্রে। এটি প্রতি নির্দিষ্ট সময় অন্তর ফাংশন কল করবে।

Debouncing এবং Throttling দুটি গুরুত্বপূর্ণ টেকনিক, যা আপনার ওয়েব অ্যাপ্লিকেশনকে আরও দক্ষ এবং পারফরম্যান্স উন্নত করতে সাহায্য করবে। এগুলো ব্যবহার করে আপনি নির্দিষ্ট ইভেন্টের উপর কন্ট্রোল পেতে পারবেন এবং অপ্রয়োজনীয় কাজ বা রিকোয়েস্ট কমাতে পারবেন।




# Day 12

✅ **আজ আমরা `.env` ফাইল এবং কনফিগারেশন ম্যানেজমেন্ট শিখবো।**  
একটি প্রকল্পে সঠিক কনফিগারেশন সেটআপ থাকা গুরুত্বপূর্ণ, বিশেষ করে যখন আপনি বিভিন্ন পরিবেশে (ডেভেলপমেন্ট, প্রোডাকশন ইত্যাদি) কাজ করেন। `.env` ফাইল হল সেই জায়গা যেখানে আপনি পরিবেশের জন্য প্রয়োজনীয় গোপন তথ্য যেমন API কী, ডাটাবেস ইউজারনেম, পাসওয়ার্ড ইত্যাদি সংরক্ষণ করেন। এটি কোডের বাইরে থেকে সেই তথ্যগুলো সরবরাহ করে, যাতে নিরাপত্তা বজায় থাকে এবং কনফিগারেশন পরিবর্তন করা সহজ হয়।

আজকের সেশনে আমরা শিখবো কিভাবে `.env` ফাইল তৈরি করা হয় এবং কিভাবে Node.js প্রকল্পে কনফিগারেশন ম্যানেজমেন্ট করতে হয়।

---

## ⏸️ 1. `.env` ফাইল কি?

`.env` ফাইল একটি প্লেইন টেক্সট ফাইল যা পরিবেশ পরিবর্তনশীল (environment variables) সংরক্ষণ করে। সাধারণত আপনি এই ফাইলে গোপন কনফিগারেশন এবং তথ্য সংরক্ষণ করেন, যা কোডে হার্ডকোড করা যায় না যেমন ডাটাবেস ইউজারনেম, API কী ইত্যাদি। এটি Node.js প্রকল্পে `dotenv` প্যাকেজ ব্যবহার করে সহজেই লোড করা যায়।

### `.env` ফাইলের উদাহরণ:

```env
DB_HOST=localhost
DB_PORT=27017
DB_USER=myuser
DB_PASSWORD=mypassword
API_KEY=your-api-key
```

- **DB_HOST:** ডাটাবেস সার্ভারের হোস্ট।
- **DB_PORT:** ডাটাবেস সার্ভারের পোর্ট।
- **DB_USER:** ডাটাবেস ইউজারনেম।
- **DB_PASSWORD:** ডাটাবেস পাসওয়ার্ড।
- **API_KEY:** অ্যাপ্লিকেশন/API এর কীগুলি।

---

## 🚀 2. `.env` ফাইল ব্যবহার করা

### 2.1. **`dotenv` প্যাকেজ ইনস্টল করা**

প্রথমে, `dotenv` প্যাকেজ ইনস্টল করতে হবে, যা `.env` ফাইল থেকে তথ্য লোড করতে সাহায্য করবে।

```bash
npm install dotenv
```

### 2.2. **`dotenv` ব্যবহার করে `.env` ফাইল লোড করা**

এবার `.env` ফাইলটি লোড করতে `dotenv` প্যাকেজটি ব্যবহার করতে হবে। আপনাকে প্রথমেই `dotenv` প্যাকেজটি আপনার কোডে রিকোয়্যার করতে হবে।

```js
// index.js
require('dotenv').config();

// `.env` ফাইল থেকে তথ্য ব্যবহার করা
console.log(process.env.DB_HOST); // localhost
console.log(process.env.DB_USER); // myuser
```

এখানে `require('dotenv').config();` কোড লাইনটি `.env` ফাইল থেকে সমস্ত কনফিগারেশন ভেরিয়েবল লোড করবে এবং এগুলো `process.env` এর মধ্যে সংরক্ষণ করবে।

---

## 🔒 3. `.env` ফাইলকে গোপন রাখা

`.env` ফাইলটি সাধারণত গোপন তথ্য রাখে, যেমন পাসওয়ার্ড, API কীগুলি ইত্যাদি, যা আপনি গিট বা অন্য কোথাও পাবলিক করতে চান না। তাই `.env` ফাইলটি `.gitignore` ফাইলে যোগ করা উচিত, যাতে এটি গিট রিপোজিটরিতে কমিট না হয়।

### `.gitignore` ফাইলে `.env` ফাইল যোগ করা:

```bash
# .gitignore
.env
```

এটি `.env` ফাইলটি গিট রিপোজিটরিতে অনিচ্ছাকৃতভাবে পুশ হতে আটকাবে।

---

## 🔄 4. কনফিগারেশন ম্যানেজমেন্ট

### 4.1. **কনফিগারেশন ফাইল তৈরি করা**

আপনি যদি `.env` ফাইলের বাইরে আরও বেশি কনফিগারেশন প্রয়োজন অনুভব করেন, তবে আপনি একটি কনফিগারেশন ফাইল তৈরি করতে পারেন। এই ফাইলটি ডাটাবেস, API কীগুলি এবং অন্যান্য প্রয়োজনীয় কনফিগারেশন তথ্যের জন্য ব্যবহৃত হতে পারে। এখানে একটি উদাহরণ দেওয়া হলো:

```js
// config.js
require('dotenv').config();

module.exports = {
  db: {
    host: process.env.DB_HOST,
    port: process.env.DB_PORT,
    user: process.env.DB_USER,
    password: process.env.DB_PASSWORD
  },
  api: {
    key: process.env.API_KEY
  }
};
```

এখানে আপনি `.env` ফাইলের তথ্য `config.js` ফাইলে নিয়ে এসে সেটি ব্যবহার করতে পারবেন আপনার কোডের অন্যান্য অংশে।

### 4.2. **কনফিগারেশন ফাইলের ব্যবহার**

এবার `config.js` ফাইল থেকে কনফিগারেশন তথ্য ব্যবহার করা যেতে পারে:

```js
// server.js
const config = require('./config');

console.log(config.db.host); // localhost
console.log(config.api.key); // your-api-key
```

---

## 📌 In Short:

- **`.env` ফাইল:** এটি পরিবেশের জন্য গোপন কনফিগারেশন তথ্য সংরক্ষণের জন্য ব্যবহৃত হয়।
- **`dotenv` প্যাকেজ:** এটি `.env` ফাইল থেকে তথ্য লোড করে এবং আপনার Node.js প্রকল্পে ব্যবহার করার জন্য `process.env` এর মধ্যে প্রদান করে।
- **কনফিগারেশন ম্যানেজমেন্ট:** `.env` ফাইলের বাইরে আপনি একটি কনফিগারেশন ফাইল তৈরি করতে পারেন, যা আপনার প্রকল্পের সমস্ত কনফিগারেশন তথ্য রাখতে সাহায্য করবে।

এটি আপনার প্রকল্পে কনফিগারেশন ব্যবস্থাপনাকে আরও নিরাপদ, সহজ এবং পরিচালনাযোগ্য করে তোলে।







# Day 13

✅ **আজ আমরা Helper Modules তৈরি করতে শিখবো।**  
একটি প্রকল্পে কোডের পুনঃব্যবহারযোগ্যতা (reusability) বজায় রাখতে হলে, কোডটি মডুলার এবং সহজে রক্ষণাবেক্ষণযোগ্য হওয়া প্রয়োজন। Helper modules হল সেই অংশ যা সাধারণত কোনো নির্দিষ্ট কার্যক্রম (functionality) সম্পাদন করার জন্য তৈরি করা হয়, এবং সেগুলি অন্যান্য অংশে পুনঃব্যবহার করা যায়। আজকের সেশনে আমরা শিখবো কিভাবে helper modules তৈরি করা যায় এবং কিভাবে এগুলিকে অন্যান্য ফাইল থেকে ব্যবহার করা যায়।

---

## ⏸️ 1. Helper Module কি?

Helper modules হলো সেই ফাংশন বা ইউটিলিটি কোড যা বারবার ব্যবহৃত হয়। সাধারণত এই মডিউলগুলোর কাজ থাকে কোডের পুনঃব্যবহারযোগ্য অংশ তৈরি করা, যেন তা বিভিন্ন জায়গায় সহজে ব্যবহার করা যায়। উদাহরণস্বরূপ, যদি আপনার একটি অ্যাপ্লিকেশন থাকে যা বিভিন্ন জায়গায় ডেটা ফরম্যাট বা ভ্যালিডেশন চেক করে, তবে আপনি সেই কোডটি একটি helper module এ রাখতে পারেন এবং একাধিক জায়গায় ব্যবহার করতে পারেন।

---

## 🚀 2. Helper Module তৈরি করা

### 2.1. **ফাংশন তৈরি করা**

ধরা যাক, আমাদের একটি অ্যাপ্লিকেশন আছে যেখানে বারবার ডেটার সাথে কাজ করতে হবে, যেমন সংখ্যা গুলি ফরম্যাট করা, ডেটা সন্নিবেশ (parse) করা, ইত্যাদি। এই ধরনের কোড আমরা একাধিকবার লিখতে চাই না, তাই আমরা এটি একটি helper module এ রাখব।

#### উদাহরণ: `mathHelper.js` মডিউল তৈরি করা

```js
// mathHelper.js - Helper Module

// সংখ্যা যোগফল করা
function add(a, b) {
  return a + b;
}

// সংখ্যা বিয়োগফল করা
function subtract(a, b) {
  return a - b;
}

// সংখ্যা গুণফল করা
function multiply(a, b) {
  return a * b;
}

// সংখ্যা ভাগফল করা
function divide(a, b) {
  if (b === 0) {
    throw new Error('Division by zero');
  }
  return a / b;
}

module.exports = { add, subtract, multiply, divide };
```

এখানে, আমরা কিছু মৌলিক গাণিতিক অপারেশনের ফাংশন তৈরি করেছি, যা পরবর্তীতে অন্য ফাইল থেকে ব্যবহার করা যাবে।

### 2.2. **এই মডিউল ব্যবহার করা**

এখন আমরা `mathHelper.js` মডিউলটিকে আমাদের প্রধান ফাইলে ইমপোর্ট করে ব্যবহার করতে পারি।

```js
// app.js - মূল ফাইল

const mathHelper = require('./mathHelper');

const sum = mathHelper.add(5, 10);
const difference = mathHelper.subtract(10, 5);
const product = mathHelper.multiply(4, 3);
const quotient = mathHelper.divide(8, 2);

console.log('Sum:', sum);
console.log('Difference:', difference);
console.log('Product:', product);
console.log('Quotient:', quotient);
```

এখানে আমরা `mathHelper` মডিউলটি `require` করে আনি এবং তারপরে এতে থাকা ফাংশনগুলো ব্যবহার করি।

---

## 🔄 3. Helper Module গুলোর শ্রেণীবদ্ধকরণ

কখনও কখনও আপনার বিভিন্ন ধরনের হেল্পার ফাংশন থাকতে পারে, যেমন:

1. **ফাইল সিস্টেমের কাজের জন্য হেল্পার** (যেমন ফাইল তৈরি, ফাইল পড়া)
2. **ডেটা ভ্যালিডেশন হেল্পার** (যেমন ইমেইল ভ্যালিডেশন, ফোন নম্বর ভ্যালিডেশন)
3. **ডেটা ফরম্যাটিং হেল্পার** (যেমন তারিখ ফরম্যাট করা, সংখ্যা ফরম্যাট করা)

এগুলো সব আলাদা আলাদা মডিউলে ভাগ করে রাখলে কোড আরও পরিষ্কার এবং রক্ষণাবেক্ষণযোগ্য হয়ে ওঠে।

### 3.1. **ফাইল হেল্পার**

```js
// fileHelper.js - ফাইল পরিচালনা
const fs = require('fs');

// ফাইল তৈরি করা
function createFile(filename, content) {
  fs.writeFileSync(filename, content);
}

// ফাইল পড়া
function readFile(filename) {
  return fs.readFileSync(filename, 'utf-8');
}

module.exports = { createFile, readFile };
```

### 3.2. **ভ্যালিডেশন হেল্পার**

```js
// validationHelper.js - ভ্যালিডেশন
function isValidEmail(email) {
  const emailRegex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
  return emailRegex.test(email);
}

function isValidPhoneNumber(phone) {
  const phoneRegex = /^[0-9]{10}$/;
  return phoneRegex.test(phone);
}

module.exports = { isValidEmail, isValidPhoneNumber };
```

---

## 📌 In Short:

- **Helper Modules:** Helper modules হলো পুনঃব্যবহারযোগ্য কোড যা আপনার অ্যাপ্লিকেশনকে আরও কার্যকর এবং সুশৃঙ্খল করে।
- **মডিউল তৈরি করা:** আপনি কোডের বিভিন্ন অংশকে আলাদা আলাদা ফাংশনে ভাগ করে একটি helper module তৈরি করতে পারেন, যা পরে অন্যান্য ফাইল থেকে `require` করে ব্যবহার করা যাবে।
- **কনভেনশন:** Helper modules সাধারণত একক দায়িত্ব (single responsibility) পালন করে, যাতে কোডের রক্ষণাবেক্ষণ সহজ হয় এবং এটি পুনঃব্যবহারযোগ্য হয়।

এটা আপনার অ্যাপ্লিকেশনকে আরও মডুলার এবং পরিচ্ছন্ন করতে সাহায্য করবে। এগুলো ব্যবহার করে আপনি কোডের মান বজায় রাখতে পারবেন এবং নতুন ফিচার যুক্ত করতে পারবেন দ্রুত। 




# Day 14

✅ **আজকের দিনটি হবে সাপ্তাহিক পুনঃমূল্যায়ন এবং JavaScript ইউটিলিটি ফাংশনগুলির অনুশীলন।**  
JavaScript-এ অনেকগুলো শক্তিশালী ইউটিলিটি ফাংশন রয়েছে, যা আপনাকে কোড লিখতে আরও দক্ষ এবং কার্যকরী করে তোলে। এই দিনে আমরা গত ১৩ দিনের শিক্ষাগুলির পুনরাবৃত্তি করবো এবং কিছু গুরুত্বপূর্ণ ইউটিলিটি ফাংশনের উপর অনুশীলন করবো।

---

## ⏸️ 1. সাপ্তাহিক পুনঃমূল্যায়ন

আজকের দিনে আমরা কিছু গুরুত্বপূর্ণ ধারণা এবং টেকনিক্যাল স্কিলগুলির পুনঃমূল্যায়ন করবো, যা আপনি গত ১৩ দিনে শিখেছেন। এই সময়ে আপনি শিখেছেন:

- **Node.js এর মৌলিক ধারণা**: আমরা শিখেছি Node.js কী, কিভাবে এটি কাজ করে এবং কিভাবে আমরা JavaScript ব্যবহার করে সার্ভার এবং অ্যাপ্লিকেশন তৈরি করতে পারি।
- **মডিউল সিস্টেম**: আমরা মডিউল তৈরি করা এবং ব্যবহার করা শিখেছি। `require`, `module.exports` এর মাধ্যমে কিভাবে কোড ভাগ করা যায় এবং পুনঃব্যবহারযোগ্য বানানো যায়।
- **Asynchronous Programming**: আমরা কলব্যাক, প্রমিজ এবং `async/await` এর মতো শক্তিশালী টেকনিক্যাল বিষয়গুলো শিখেছি যা Node.js-এ আসিঙ্ক্রোনাস কাজকে আরও সহজ করে তোলে।
- **Enviroment Variables**: `.env` ফাইল এবং কনফিগারেশন ম্যানেজমেন্ট শিখেছি যাতে আমাদের অ্যাপ্লিকেশন আরো নিরাপদ এবং পরিচালনাযোগ্য হয়।

আজকের দিনে, আমরা এগুলোর পুনরাবৃত্তি করে এগুলিকে আরও ভালভাবে আত্মস্থ করবো।

---

## 🚀 2. JS ইউটিলিটি ফাংশনগুলির অনুশীলন

JavaScript এর অনেক ইউটিলিটি ফাংশন রয়েছে যেগুলি আপনাকে সাধারণ কাজগুলো দ্রুত এবং সহজে করতে সহায়তা করে। চলুন আমরা কিছু প্র্যাকটিস করি।

### 2.1. **Array Methods:**

#### 2.1.1. `map()`

`map()` ফাংশনটি অ্যারের প্রতিটি উপাদানকে একটি নির্দিষ্ট ফাংশন প্রয়োগ করে এবং একটি নতুন অ্যারে রিটার্ন করে।

```js
// উদাহরণ
const numbers = [1, 2, 3, 4, 5];
const doubledNumbers = numbers.map(num => num * 2);
console.log(doubledNumbers); // [2, 4, 6, 8, 10]
```

#### 2.1.2. `filter()`

`filter()` ফাংশনটি একটি শর্তের ভিত্তিতে কিছু উপাদান ফিল্টার করে এবং একটি নতুন অ্যারে রিটার্ন করে।

```js
// উদাহরণ
const numbers = [1, 2, 3, 4, 5, 6];
const evenNumbers = numbers.filter(num => num % 2 === 0);
console.log(evenNumbers); // [2, 4, 6]
```

#### 2.1.3. `reduce()`

`reduce()` ফাংশনটি একটি অ্যারের সকল উপাদানকে একত্রে সংযুক্ত করে একটি একক মান তৈরি করে।

```js
// উদাহরণ
const numbers = [1, 2, 3, 4, 5];
const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
console.log(sum); // 15
```

---

### 2.2. **String Methods:**

#### 2.2.1. `split()`

`split()` ফাংশনটি একটি স্ট্রিংকে একটি নির্দিষ্ট ডিলিমিটার দ্বারা বিভক্ত করে একটি অ্যারে তৈরি করে।

```js
// উদাহরণ
const sentence = "JavaScript is awesome";
const words = sentence.split(" ");
console.log(words); // ['JavaScript', 'is', 'awesome']
```

#### 2.2.2. `join()`

`join()` ফাংশনটি একটি অ্যারের সমস্ত উপাদানকে একটি স্ট্রিংয়ে সংযুক্ত করে একটি একক স্ট্রিং তৈরি করে।

```js
// উদাহরণ
const words = ['JavaScript', 'is', 'awesome'];
const sentence = words.join(" ");
console.log(sentence); // "JavaScript is awesome"
```

#### 2.2.3. `replace()`

`replace()` ফাংশনটি একটি স্ট্রিংয়ের একটি নির্দিষ্ট অংশকে পরিবর্তন করে।

```js
// উদাহরণ
const sentence = "JavaScript is awesome";
const newSentence = sentence.replace("awesome", "powerful");
console.log(newSentence); // "JavaScript is powerful"
```

---

### 2.3. **Object Methods:**

#### 2.3.1. `Object.keys()`

`Object.keys()` ফাংশনটি একটি অবজেক্টের সমস্ত কীসমূহের একটি অ্যারে রিটার্ন করে।

```js
// উদাহরণ
const user = { name: "Rakib", age: 23, city: "Dhaka" };
const keys = Object.keys(user);
console.log(keys); // ["name", "age", "city"]
```

#### 2.3.2. `Object.values()`

`Object.values()` ফাংশনটি একটি অবজেক্টের সমস্ত মানের একটি অ্যারে রিটার্ন করে।

```js
// উদাহরণ
const user = { name: "Rakib", age: 23, city: "Dhaka" };
const values = Object.values(user);
console.log(values); // ["Rakib", 23, "Dhaka"]
```

---

### 2.4. **Set Methods:**

#### 2.4.1. `add()`

`add()` ফাংশনটি একটি `Set` এ একটি নতুন মান যোগ করে।

```js
// উদাহরণ
const uniqueNumbers = new Set([1, 2, 3, 4, 5]);
uniqueNumbers.add(6);
console.log(uniqueNumbers); // Set { 1, 2, 3, 4, 5, 6 }
```

#### 2.4.2. `has()`

`has()` ফাংশনটি চেক করে যে একটি `Set` এ নির্দিষ্ট মানটি রয়েছে কিনা।

```js
// উদাহরণ
const uniqueNumbers = new Set([1, 2, 3, 4, 5]);
console.log(uniqueNumbers.has(3)); // true
console.log(uniqueNumbers.has(7)); // false
```

---

## 📌 In Short:

- **Array Methods:** `map()`, `filter()`, এবং `reduce()` এর মাধ্যমে অ্যারের সাথে কাজ করার দক্ষতা অর্জন করা।
- **String Methods:** `split()`, `join()`, এবং `replace()` এর মাধ্যমে স্ট্রিংয়ের সাথে কাজ করা।
- **Object Methods:** `Object.keys()` এবং `Object.values()` এর মাধ্যমে অবজেক্টের ডাটা অ্যাক্সেস করা।
- **Set Methods:** `add()` এবং `has()` এর মাধ্যমে `Set` ডাটা স্ট্রাকচার ব্যবহার করা।

আজকের অনুশীলনের মাধ্যমে আপনি JavaScript এর কিছু গুরুত্বপূর্ণ ইউটিলিটি ফাংশনের কাজ শিখেছেন, যা কোড লেখাকে আরও শক্তিশালী এবং দক্ষ করে তুলবে।

এটি আপনার প্রকল্পগুলির জন্য কোড লেখা এবং সমস্যা সমাধানে সহায়ক হবে।  
আজকের সেশন শেষ, আবার দেখা হবে পরবর্তী দিনের শিখনে! 🚀



