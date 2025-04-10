# Day 36

✅ **আজকের দিনটি: `zod` ইন্সটল করা এবং স্কিমা ভ্যালিডেশন**

আজকের দিনে আমরা **`zod`** প্যাকেজটি ইন্সটল করবো এবং এটি ব্যবহার করে **স্কিমা ভ্যালিডেশন** করার প্রক্রিয়া শিখবো। `zod` একটি সহজ এবং শক্তিশালী লাইব্রেরি যা TypeScript-এর সাথে খুব ভালোভাবে কাজ করে এবং ডাটা ভ্যালিডেশনকে আরও সহজ করে তোলে।

---

## ⏸️ 1. `zod` প্যাকেজ ইন্সটল করা

প্রথমেই, `zod` ইন্সটল করতে হবে। আপনি **npm** বা **yarn** দিয়ে এটি ইন্সটল করতে পারেন।

### npm দিয়ে ইন্সটল:
```bash
npm install zod
```

### yarn দিয়ে ইন্সটল:
```bash
yarn add zod
```

এটা ইন্সটল করার পর আমরা এটি ব্যবহার করে ডাটা ভ্যালিডেশন করতে পারবো।

---

## ⏸️ 2. `zod` দিয়ে স্কিমা ভ্যালিডেশন

**zod** দিয়ে স্কিমা ভ্যালিডেশন করতে আমরা একটি স্কিমা তৈরি করবো এবং সেই স্কিমা ব্যবহার করে ইনপুট ডাটা ভ্যালিডেশন করবো।

### `zod` ব্যবহার করে স্কিমা তৈরি

এখানে আমরা একটি `User` স্কিমা তৈরি করবো যেটিতে `name`, `email`, এবং `age` প্রপার্টি থাকবে।

```js
const { z } = require('zod');

// User স্কিমা তৈরি
const userSchema = z.object({
  name: z.string().min(3, 'নামটি কমপক্ষে ৩ অক্ষরের হতে হবে'),
  email: z.string().email('এটি একটি বৈধ ইমেইল হতে হবে'),
  age: z.number().min(18, 'বয়স কমপক্ষে ১৮ বছর হতে হবে')
});

// ভ্যালিডেশন ফাংশন
const validateUser = (userData) => {
  try {
    userSchema.parse(userData); // এখানে `parse` মেথড ব্যবহার করছি
    console.log('ডাটা ভ্যালিড');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

// ভ্যালিড ডাটা
const user = { name: 'Rakib', email: 'rakib@example.com', age: 23 };
validateUser(user);

// অকার্যকর ডাটা
const invalidUser = { name: 'Ra', email: 'rakibexample.com', age: 17 };
validateUser(invalidUser);
```

এখানে:
- `z.object` দিয়ে একটি স্কিমা তৈরি করা হয়েছে, যেখানে `name`, `email`, এবং `age` প্রপার্টি রয়েছে।
- `z.string()` এবং `z.number()` ব্যবহার করে আমরা `name`, `email`, এবং `age` এর জন্য নির্দিষ্ট ভ্যালিডেশন শর্ত দিয়েছি।
- `parse` মেথড দিয়ে ডাটা ভ্যালিডেশন করা হয়। যদি ডাটা সঠিক না হয়, তাহলে একটি ত্রুটি প্রদান করবে।

---

## ⏸️ 3. `zod` দিয়ে কাস্টম ভ্যালিডেশন

কখনও কখনও আমাদের বিশেষ ভ্যালিডেশন শর্ত দিতে হতে পারে। যেমন, বয়স যদি ১৮ বছরের বেশি না হয় তবে সঠিক নয়। এই ধরনের কাস্টম ভ্যালিডেশনও `zod` দিয়ে করা সম্ভব।

### কাস্টম ভ্যালিডেশন উদাহরণ

```js
const { z } = require('zod');

// কাস্টম ভ্যালিডেশন ফাংশন
const ageCheck = (age) => {
  if (age < 18) {
    throw new Error('বয়স কমপক্ষে ১৮ বছর হতে হবে');
  }
  return age;
};

// User স্কিমা কাস্টম ভ্যালিডেশন সহ
const userSchema = z.object({
  name: z.string().min(3, 'নামটি কমপক্ষে ৩ অক্ষরের হতে হবে'),
  email: z.string().email('এটি একটি বৈধ ইমেইল হতে হবে'),
  age: z.number().refine(ageCheck, 'বয়স কমপক্ষে ১৮ বছর হতে হবে')
});

// ডাটা ভ্যালিডেশন
const user = { name: 'Rakib', email: 'rakib@example.com', age: 25 };
userSchema.parse(user); // এটি সফল হবে
```

এখানে:
- আমরা `refine` মেথড ব্যবহার করে একটি কাস্টম ভ্যালিডেশন যুক্ত করেছি, যা বয়স ১৮ বছরের কম হলে ত্রুটি দেবে।

---

## ⏸️ 4. `zod` এর সুবিধা ও ব্যবহার

**zod** এর কিছু গুরুত্বপূর্ণ সুবিধা:

1. **TypeScript Integration**: TypeScript এর সাথে খুব ভালোভাবে কাজ করে।
2. **Simple Syntax**: খুবই সহজ এবং পরিষ্কার সিনট্যাক্স।
3. **Chaining**: একাধিক ভ্যালিডেশন চেইন করা যায়।
4. **Error Handling**: সহজ এবং পরিষ্কার ত্রুটি বার্তা প্রদান করে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **`zod` প্যাকেজ ইন্সটল করা** এবং সেটি ব্যবহার করে **স্কিমা ভ্যালিডেশন** করা।
- **Custom Validation** সহ স্কিমা তৈরি করা।
- **Error Handling** এবং কাস্টম ভ্যালিডেশন ফাংশন ব্যবহার করা।

এখন আপনার প্রজেক্টে ডাটা ভ্যালিডেশন আরও সহজ এবং নিরাপদ হবে! 🛡️🚀







# Day 37

✅ **আজকের দিনটি: `zod` ব্যবহার করে ইউজার, প্রোডাক্ট এবং অর্ডার ফর্মে ভ্যালিডেশন প্রয়োগ করা**

আজকের দিনে আমরা **`zod`** প্যাকেজটি ব্যবহার করে **ইউজার**, **প্রোডাক্ট** এবং **অর্ডার** ফর্মে **ভ্যালিডেশন** প্রয়োগ করবো। এই ফর্মগুলোতে বিভিন্ন ধরনের ইনপুট থেকে সঠিক ডাটা গ্রহণ করতে আমরা `zod` স্কিমা ভ্যালিডেশন ব্যবহার করবো।

---

## ⏸️ 1. ইউজার ফর্মের জন্য `zod` স্কিমা তৈরি করা

প্রথমে, ইউজারের নাম, ইমেইল, এবং বয়সের জন্য একটি ফর্ম তৈরি করতে হবে এবং সেখানে `zod` স্কিমা দিয়ে ভ্যালিডেশন প্রয়োগ করবো।

### ইউজার স্কিমা উদাহরণ

```js
const { z } = require('zod');

// ইউজার স্কিমা তৈরি
const userSchema = z.object({
  name: z.string().min(3, 'নামটি কমপক্ষে ৩ অক্ষরের হতে হবে'),
  email: z.string().email('এটি একটি বৈধ ইমেইল হতে হবে'),
  age: z.number().min(18, 'বয়স কমপক্ষে ১৮ বছর হতে হবে')
});

// ইউজার ডাটা ভ্যালিডেশন
const validateUser = (userData) => {
  try {
    userSchema.parse(userData); // `parse` মেথড দিয়ে ভ্যালিডেশন
    console.log('ইউজার ডাটা সঠিক');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

const user = { name: 'Rakib', email: 'rakib@example.com', age: 23 };
validateUser(user);
```

এখানে:
- `z.object` দিয়ে ইউজার স্কিমা তৈরি করা হয়েছে।
- `z.string()` এবং `z.number()` দিয়ে ডাটা ভ্যালিডেশন করা হয়েছে।

---

## ⏸️ 2. প্রোডাক্ট ফর্মের জন্য `zod` স্কিমা তৈরি করা

এখন আমরা একটি প্রোডাক্ট ফর্ম তৈরি করবো, যেখানে প্রোডাক্টের নাম, দাম এবং স্টক কান্তিটি থাকবে।

### প্রোডাক্ট স্কিমা উদাহরণ

```js
const { z } = require('zod');

// প্রোডাক্ট স্কিমা তৈরি
const productSchema = z.object({
  name: z.string().min(3, 'প্রোডাক্টের নাম কমপক্ষে ৩ অক্ষরের হতে হবে'),
  price: z.number().min(1, 'প্রোডাক্টের দাম ১ টাকা অথবা তার বেশি হতে হবে'),
  quantity: z.number().min(1, 'প্রোডাক্টের পরিমাণ কমপক্ষে ১ হতে হবে')
});

// প্রোডাক্ট ডাটা ভ্যালিডেশন
const validateProduct = (productData) => {
  try {
    productSchema.parse(productData);
    console.log('প্রোডাক্ট ডাটা সঠিক');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

const product = { name: 'Mobile', price: 1000, quantity: 10 };
validateProduct(product);
```

এখানে:
- `z.string().min(3)` দিয়ে প্রোডাক্টের নামের জন্য মিনিমাম ৩ অক্ষরের শর্ত দেওয়া হয়েছে।
- `z.number().min(1)` দিয়ে প্রোডাক্টের দাম এবং পরিমাণের জন্য একটি ন্যূনতম মান নির্ধারণ করা হয়েছে।

---

## ⏸️ 3. অর্ডার ফর্মের জন্য `zod` স্কিমা তৈরি করা

এখন আমরা একটি অর্ডার ফর্ম তৈরি করবো, যেখানে অর্ডারের ইউজার আইডি, প্রোডাক্ট আইডি এবং পরিমাণ থাকবে।

### অর্ডার স্কিমা উদাহরণ

```js
const { z } = require('zod');

// অর্ডার স্কিমা তৈরি
const orderSchema = z.object({
  userId: z.string().uuid('ভ্যালিড ইউজার আইডি প্রদান করুন'),
  productId: z.string().uuid('ভ্যালিড প্রোডাক্ট আইডি প্রদান করুন'),
  quantity: z.number().min(1, 'অর্ডারের পরিমাণ কমপক্ষে ১ হতে হবে')
});

// অর্ডার ডাটা ভ্যালিডেশন
const validateOrder = (orderData) => {
  try {
    orderSchema.parse(orderData);
    console.log('অর্ডার ডাটা সঠিক');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

const order = { userId: '123e4567-e89b-12d3-a456-426614174000', productId: '123e4567-e89b-12d3-a456-426614174000', quantity: 5 };
validateOrder(order);
```

এখানে:
- `z.string().uuid()` দিয়ে ইউজার এবং প্রোডাক্ট আইডির জন্য UUID ভ্যালিডেশন করা হয়েছে।
- `z.number().min(1)` দিয়ে পরিমাণের জন্য ন্যূনতম ১ এর শর্ত দেওয়া হয়েছে।

---

## ⏸️ 4. ফর্মে ভ্যালিডেশন প্রয়োগ করা

উপরোক্ত স্কিমাগুলো এখন ফর্মের সাথে ইন্টিগ্রেট করা যেতে পারে। আপনি যখন ইউজার, প্রোডাক্ট বা অর্ডার ফর্ম সাবমিট করবেন, তখন এই স্কিমাগুলির সাহায্যে ডাটা ভ্যালিডেশন করে তা সঠিক কিনা পরীক্ষা করা যাবে।

### উদাহরণ:

```js
const submitForm = (userData) => {
  try {
    userSchema.parse(userData); // ইউজার ফর্ম ভ্যালিডেশন
    console.log('ফর্ম সাবমিট সফল');
  } catch (error) {
    console.log('ফর্ম ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

// ফর্মের ইনপুট ডাটা
const userData = { name: 'John Doe', email: 'john@example.com', age: 30 };
submitForm(userData);
```

এখানে:
- ফর্ম সাবমিট করার সময় `parse` মেথড ব্যবহার করে ইনপুট ডাটার ভ্যালিডেশন করা হচ্ছে।
- যদি কোন ত্রুটি থাকে, তবে তা কনসোলে দেখানো হবে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **ইউজার, প্রোডাক্ট এবং অর্ডার ফর্মের জন্য `zod` ব্যবহার করে স্কিমা তৈরি করা**।
- **ফর্ম সাবমিট করার আগে ডাটা ভ্যালিডেশন** করা।
- **UUID এবং অন্যান্য ভ্যালিডেশন শর্ত** প্রয়োগ করা।

এখন আপনি আপনার অ্যাপ্লিকেশনে শক্তিশালী ভ্যালিডেশন যুক্ত করতে পারবেন! 🛡️🚀







# Day 38

✅ **আজকের দিনটি: Nested Object Validation**

আজকের দিনে আমরা **নেস্টেড অবজেক্ট ভ্যালিডেশন** শিখবো। যখন আমাদের ডাটা একাধিক স্তরের অবজেক্ট বা অ্যারে ধারণ করে, তখন `zod` ব্যবহার করে আমরা সেই নেস্টেড অবজেক্টগুলো ভ্যালিডেট করতে পারি।

---

## ⏸️ 1. নেস্টেড অবজেক্টের জন্য `zod` স্কিমা তৈরি করা

প্রথমে, একটি নেস্টেড অবজেক্ট তৈরি করবো যেখানে ইউজারের নাম, ঠিকানা, এবং ফোন নম্বর থাকবে। এখানে ঠিকানা আবার একটি নেস্টেড অবজেক্ট হতে পারে, যাতে রাস্তা, শহর এবং পোস্টাল কোড থাকবে।

### নেস্টেড অবজেক্ট স্কিমা উদাহরণ

```js
const { z } = require('zod');

// নেস্টেড ইউজার স্কিমা তৈরি
const addressSchema = z.object({
  street: z.string().min(3, 'রাস্তার নাম কমপক্ষে ৩ অক্ষরের হতে হবে'),
  city: z.string().min(3, 'শহরের নাম কমপক্ষে ৩ অক্ষরের হতে হবে'),
  postalCode: z.string().min(5, 'পোস্টাল কোড ৫ অক্ষরের হতে হবে'),
});

const userSchema = z.object({
  name: z.string().min(3, 'নামটি কমপক্ষে ৩ অক্ষরের হতে হবে'),
  email: z.string().email('এটি একটি বৈধ ইমেইল হতে হবে'),
  address: addressSchema, // নেস্টেড অবজেক্ট ভ্যালিডেশন
  phone: z.string().regex(/^\+?[1-9]\d{1,14}$/, 'ভ্যালিড ফোন নম্বর প্রদান করুন'), // ফোন নম্বরের জন্য regex
});

// ইউজার ডাটা ভ্যালিডেশন
const validateUser = (userData) => {
  try {
    userSchema.parse(userData); // `parse` মেথড দিয়ে ভ্যালিডেশন
    console.log('ইউজার ডাটা সঠিক');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

const user = {
  name: 'Rakib',
  email: 'rakib@example.com',
  address: {
    street: 'Gulshan Ave',
    city: 'Dhaka',
    postalCode: '1212',
  },
  phone: '+8801712345678',
};

validateUser(user);
```

এখানে:
- `addressSchema` একটি নেস্টেড অবজেক্টের স্কিমা যা ইউজারের ঠিকানা ভ্যালিডেশন করে।
- ইউজারের ডাটা যখন `userSchema.parse()` দিয়ে ভ্যালিডেট করা হয়, তখন নেস্টেড অবজেক্টও ভ্যালিডেট হয় স্বয়ংক্রিয়ভাবে।

---

## ⏸️ 2. নেস্টেড অ্যারে ভ্যালিডেশন

ধরা যাক, আমাদের কাছে একটি প্রোডাক্টের অর্ডার তালিকা আছে যেখানে বিভিন্ন প্রোডাক্ট রয়েছে। প্রতিটি প্রোডাক্টের নাম, দাম এবং পরিমাণ থাকতে পারে। আমরা `zod` ব্যবহার করে অ্যারের প্রতিটি আইটেমের ভ্যালিডেশনও করতে পারি।

### অ্যারে স্কিমা উদাহরণ

```js
const { z } = require('zod');

// প্রোডাক্ট স্কিমা তৈরি
const productSchema = z.object({
  name: z.string().min(3, 'প্রোডাক্টের নাম কমপক্ষে ৩ অক্ষরের হতে হবে'),
  price: z.number().min(1, 'প্রোডাক্টের দাম কমপক্ষে ১ টাকা হতে হবে'),
  quantity: z.number().min(1, 'প্রোডাক্টের পরিমাণ কমপক্ষে ১ হতে হবে'),
});

// অর্ডার স্কিমা তৈরি
const orderSchema = z.object({
  userId: z.string().uuid('ভ্যালিড ইউজার আইডি প্রদান করুন'),
  products: z.array(productSchema), // অ্যারে ভ্যালিডেশন
  totalAmount: z.number().min(1, 'মোট পরিমাণ কমপক্ষে ১ টাকা হতে হবে'),
});

// অর্ডার ডাটা ভ্যালিডেশন
const validateOrder = (orderData) => {
  try {
    orderSchema.parse(orderData);
    console.log('অর্ডার ডাটা সঠিক');
  } catch (error) {
    console.log('ভ্যালিডেশন ত্রুটি:', error.errors);
  }
};

const order = {
  userId: '123e4567-e89b-12d3-a456-426614174000',
  products: [
    { name: 'Mobile', price: 1000, quantity: 2 },
    { name: 'Headphones', price: 500, quantity: 3 },
  ],
  totalAmount: 3500,
};

validateOrder(order);
```

এখানে:
- `z.array(productSchema)` দিয়ে অ্যারের প্রতিটি আইটেমের জন্য প্রোডাক্ট ভ্যালিডেশন করা হচ্ছে।
- প্রতিটি প্রোডাক্টের নাম, দাম এবং পরিমাণ চেক করা হচ্ছে।

---

## ⏸️ 3. ভ্যালিডেশন ত্রুটি হ্যান্ডলিং

যখন নেস্টেড অবজেক্ট বা অ্যারে ভ্যালিডেশন হয়, তখন প্রতিটি স্তরের জন্য ত্রুটিগুলি আলাদাভাবে প্রদর্শন করা হয়। আপনি `error.errors` এর মাধ্যমে এই ত্রুটিগুলি দেখতে পারেন।

### ভ্যালিডেশন ত্রুটি উদাহরণ

```js
const user = {
  name: 'Ra',
  email: 'rakib@example.com',
  address: {
    street: 'Gulshan Ave',
    city: '',
    postalCode: '1212',
  },
  phone: '12345',
};

try {
  userSchema.parse(user);
} catch (error) {
  console.log('ভ্যালিডেশন ত্রুটি:', error.errors); // এখানে আমরা নেস্টেড ত্রুটি দেখবো
}
```

এখানে:
- `name` কমপক্ষে ৩ অক্ষরের হতে হবে, তবে এটি ২ অক্ষরের।
- `city` খালি থাকলে ত্রুটি প্রদর্শিত হবে।
- `phone` সঠিক ফরম্যাটে নেই।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **নেস্টেড অবজেক্ট ভ্যালিডেশন** কিভাবে করতে হয়।
- **অ্যারে ভ্যালিডেশন** কিভাবে করা যায়।
- **ভ্যালিডেশন ত্রুটি হ্যান্ডলিং** কিভাবে করা হয়।

আজকের দিনে আপনি শিখলেন কিভাবে নেস্টেড অবজেক্ট এবং অ্যারে ভ্যালিডেশন করতে হয়, যা আপনার অ্যাপ্লিকেশনে ডাটা সঠিকভাবে ইনপুট গ্রহণ করতে সাহায্য করবে। 🛡️🚀






# Day 39

✅ **আজকের দিনটি: Middleware for Zod**

আজকের দিনে আমরা **Zod** এর জন্য **Middleware** তৈরি করতে শিখবো। `Zod` ব্যবহার করে, আমরা ডাটা ভ্যালিডেশন সহজে এবং কার্যকরভাবে করতে পারি, এবং এটি **Middleware** এর মাধ্যমে আমাদের Express রাউটগুলিতে ইন্টিগ্রেট করতে পারি।

---

## ⏸️ 1. Middleware কী?

**Middleware** হলো একটি ফাংশন যা **HTTP request** এর আগে বা পরে কার্যকর হয়। এটি সাধারণত request বা response এর সাথে কাজ করে, যেমন ডাটা ভ্যালিডেশন, authentication, logging ইত্যাদি।

### Middleware উদাহরণ

```js
const express = require('express');
const { z } = require('zod');
const app = express();

// সহজ একটি Middleware উদাহরণ
const simpleMiddleware = (req, res, next) => {
  console.log('Middleware কার্যকর হচ্ছে...');
  next(); // পরবর্তী Middleware বা Route Handler এ যেতে অনুমতি দেয়
};

app.use(simpleMiddleware); // Middleware ব্যবহার
```

---

## ⏸️ 2. Zod এর সাথে Middleware ব্যবহার

`Zod` এর মাধ্যমে ভ্যালিডেশন করার জন্য আমরা একটি Middleware তৈরি করতে পারি, যা ইনকামিং request এর ডাটা চেক করবে। উদাহরণস্বরূপ, আমরা ইউজারের ইনপুটের ডাটা ভ্যালিডেট করব যাতে তা সঠিক ফরম্যাটে থাকে।

### Zod Middleware উদাহরণ

```js
const express = require('express');
const { z } = require('zod');
const app = express();

// Request body কে JSON ফরম্যাটে প্যার্স করার জন্য
app.use(express.json());

// ইউজার ভ্যালিডেশন স্কিমা
const userSchema = z.object({
  name: z.string().min(3, 'নামটি কমপক্ষে ৩ অক্ষরের হতে হবে'),
  email: z.string().email('এটি একটি বৈধ ইমেইল হতে হবে'),
  age: z.number().int().min(18, 'বয়স কমপক্ষে ১৮ হতে হবে'),
});

// Zod Middleware তৈরি
const validateUserMiddleware = (req, res, next) => {
  try {
    // ইউজার ইনপুট ভ্যালিডেশন
    userSchema.parse(req.body);
    next(); // যদি ভ্যালিড হয় তবে পরবর্তী Middleware বা Route Handler এ যেতে অনুমতি দেয়
  } catch (error) {
    res.status(400).json({
      message: 'ভ্যালিডেশন ত্রুটি',
      errors: error.errors, // Zod এর ত্রুটির বিস্তারিত
    });
  }
};

// একটি POST রাউট, যেখানে Zod Middleware ব্যবহার করা হবে
app.post('/register', validateUserMiddleware, (req, res) => {
  res.status(200).json({ message: 'ইউজার সফলভাবে নিবন্ধিত হয়েছে!' });
});

// সিঙ্গেল্টন সার্ভার চালু করা
app.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});
```

এখানে:
- `userSchema` একটি Zod স্কিমা যা ইউজারের নাম, ইমেইল এবং বয়সের জন্য ভ্যালিডেশন করে।
- `validateUserMiddleware` নামক Middleware টি `req.body` কে Zod স্কিমার মাধ্যমে ভ্যালিডেট করে।
- যদি কোনো ভ্যালিডেশন ত্রুটি ঘটে, তবে `400` status কোডসহ ত্রুটির বিস্তারিত ক্লায়েন্টকে পাঠানো হয়।

---

## ⏸️ 3. Middleware এর মাধ্যমে মডিউল ভ্যালিডেশন হ্যান্ডলিং

এভাবে আপনি যে কোনো মডিউলের জন্য Zod এর মাধ্যমে ভ্যালিডেশন করতে পারেন। এটি আপনার API ডেভেলপমেন্টকে আরও কার্যকর এবং নিরাপদ করে তুলবে, কারণ ডাটা সঠিকভাবে ইনপুট হবে।

### আরো একটি উদাহরণ: প্রোডাক্ট ভ্যালিডেশন

```js
const productSchema = z.object({
  name: z.string().min(3, 'প্রোডাক্টের নাম কমপক্ষে ৩ অক্ষরের হতে হবে'),
  price: z.number().min(1, 'প্রোডাক্টের দাম কমপক্ষে ১ টাকা হতে হবে'),
  quantity: z.number().min(1, 'প্রোডাক্টের পরিমাণ কমপক্ষে ১ হতে হবে'),
});

// প্রোডাক্ট ভ্যালিডেশন Middleware
const validateProductMiddleware = (req, res, next) => {
  try {
    productSchema.parse(req.body);
    next();
  } catch (error) {
    res.status(400).json({
      message: 'প্রোডাক্ট ভ্যালিডেশন ত্রুটি',
      errors: error.errors,
    });
  }
};

app.post('/products', validateProductMiddleware, (req, res) => {
  res.status(201).json({ message: 'প্রোডাক্ট সফলভাবে যুক্ত হয়েছে!' });
});
```

এখানে:
- `validateProductMiddleware` প্রোডাক্টের তথ্য ভ্যালিডেশন করে এবং ত্রুটি থাকলে তা জানায়।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Zod এর মাধ্যমে Middleware তৈরি করার পদ্ধতি**।
- **Zod স্কিমা ব্যবহার করে ডাটা ভ্যালিডেশন**।
- **ভ্যালিডেশন ত্রুটি হ্যান্ডলিং**।

আজকের দিনে আপনি শিখলেন কিভাবে **Express Middleware** এর মাধ্যমে `Zod` ব্যবহার করে API রাউটগুলির ডাটা ভ্যালিডেশন করতে হয় এবং ত্রুটি হ্যান্ডলিং করতে হয়। এটি আপনার API কে আরো সুরক্ষিত এবং কার্যকরী করবে। 🛡️🚀





# Day 40

✅ **আজকের দিনটি: Custom error classes + centralized error handler**

আজকের দিনে আমরা **Custom Error Classes** এবং **Centralized Error Handler** তৈরি করতে শিখবো। এর মাধ্যমে, আমাদের অ্যাপ্লিকেশন এর ত্রুটি হ্যান্ডলিং আরও পরিষ্কার এবং সুসংগঠিত হবে। Custom error classes ব্যবহার করে আপনি ত্রুটি সম্পর্কিত আরও বিস্তারিত তথ্য পেতে পারবেন, এবং centralized error handler ব্যবহার করে সকল ত্রুটির জন্য একটি একক পদ্ধতিতে হ্যান্ডলিং করতে পারবেন।

---

## ⏸️ 1. Custom Error Classes

**Custom error classes** তৈরি করলে আমরা ত্রুটির ধরন এবং মেসেজ নির্দিষ্টভাবে কাস্টমাইজ করতে পারি। এতে আমাদের ত্রুটির তথ্য গুলো আরো পরিষ্কার এবং ব্যবহারযোগ্য হয়।

### Custom Error Class উদাহরণ

```js
class AppError extends Error {
  constructor(message, statusCode) {
    super(message); // Error এর message সেট করা
    this.statusCode = statusCode || 500; // status code সেট করা (ডিফল্ট 500)
    this.isOperational = true; // operational error হিসেবে চিহ্নিত করা
    Error.captureStackTrace(this, this.constructor); // Stack trace এর সাথে error capture করা
  }
}

module.exports = AppError;
```

এখানে:
- **AppError** একটি কাস্টম ক্লাস যা `Error` ক্লাস থেকে এক্সটেন্ড করা হয়েছে।
- **statusCode** এবং **message** এর মাধ্যমে ত্রুটির বিস্তারিত ব্যাখ্যা করা হচ্ছে।
- **isOperational** একটি ফ্ল্যাগ যা operational error এর সাথে সম্পর্কিত।

---

## ⏸️ 2. Centralized Error Handler

**Centralized Error Handler** তৈরি করলে আমাদের অ্যাপ্লিকেশনের সমস্ত ত্রুটি একটি একক জায়গা থেকে হ্যান্ডল করা সম্ভব হয়। এতে, আমরা ত্রুটির ধরন এবং মেসেজের উপর ভিত্তি করে উপযুক্ত রেসপন্স প্রদান করতে পারি।

### Centralized Error Handler উদাহরণ

```js
const AppError = require('./utils/appError');

const handleError = (err, req, res, next) => {
  // Operational errors
  if (err.isOperational) {
    return res.status(err.statusCode).json({
      status: 'error',
      message: err.message,
    });
  }

  // Programming or other unknown errors
  console.error('ERROR 💥:', err); // সার্ভার এর লগে ত্রুটি দেখানো
  return res.status(500).json({
    status: 'error',
    message: 'Something went wrong!',
  });
};

module.exports = handleError;
```

এখানে:
- **handleError** একটি মিডলওয়্যার ফাংশন যা সমস্ত ত্রুটি হ্যান্ডল করে।
- **err.isOperational** চেক করে, যদি ত্রুটি operational হয়, তবে সঠিক status code এবং মেসেজ পাঠানো হয়, নতুবা সার্ভার ত্রুটির মেসেজ প্রদান করা হয়।

---

## ⏸️ 3. Error Handling in Routes

এখন আমরা আমাদের **custom error class** এবং **centralized error handler** রাউটের সাথে সংযুক্ত করবো।

### Express রাউটে Error Handling

```js
const express = require('express');
const AppError = require('./utils/appError');
const handleError = require('./utils/handleError');

const app = express();

app.get('/error', (req, res, next) => {
  const error = new AppError('This is a custom error', 400);
  next(error); // Error next() ফাংশনে পাঠানো হচ্ছে
});

// Centralized error handler ব্যবহার
app.use(handleError);

app.listen(3000, () => {
  console.log('Server is running on http://localhost:3000');
});
```

এখানে:
- `/error` রাউট একটি কাস্টম ত্রুটি তৈরি করছে এবং `next(error)` এর মাধ্যমে তা error handler এ পাঠাচ্ছে।
- **handleError** মডিউলটি ত্রুটি হ্যান্ডলিং করছে, এবং response এ সঠিক status code এবং message পাঠানো হচ্ছে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Custom error classes** তৈরির মাধ্যমে কাস্টম ত্রুটি তৈরি করা।
- **Centralized error handler** তৈরি করে সমস্ত ত্রুটি এক জায়গায় হ্যান্ডল করা।
- **Express** রাউট ও error handler এর মাধ্যমে কিভাবে ত্রুটি সমাধান করা হয়।

আজকের দিনে আপনি শিখলেন কিভাবে **custom error classes** এবং **centralized error handler** তৈরি করতে হয়। এটি আপনার অ্যাপ্লিকেশনকে আরও ক্লিন এবং ম্যানেজযোগ্য বানাবে, বিশেষ করে ত্রুটি হ্যান্ডলিংয়ের ক্ষেত্রে। 🛠️🚀





# Day 41

✅ **আজকের দিনটি: Test errors and refactor**

আজকের দিনে আমরা **এরর টেস্টিং** এবং **কোড রিফ্যাক্টরিং** শিখবো। একসাথে, আমরা বুঝতে পারবো কিভাবে আমাদের ত্রুটি ব্যবস্থাপনা সঠিকভাবে কাজ করছে এবং কিভাবে কোডটি আরো দক্ষ এবং পরিষ্কার করা যায়।

---

## ⏸️ 1. Error Testing

**Error testing** এর মাধ্যমে আমরা নিশ্চিত হতে পারি যে আমাদের **custom errors** এবং **centralized error handler** ঠিকভাবে কাজ করছে। এটি আমাদের অ্যাপ্লিকেশন এর ত্রুটির আচরণ এবং প্রতিক্রিয়া নিশ্চিত করতে সাহায্য করে।

### Error Testing উদাহরণ

```js
const request = require('supertest');
const app = require('../app'); // Express অ্যাপ্লিকেশন

describe('GET /error', () => {
  it('should return a 400 error for custom error', async () => {
    const res = await request(app).get('/error'); // /error রাউটে GET রিকোয়েস্ট
    expect(res.status).toBe(400); // status কোড চেক করা
    expect(res.body.message).toBe('This is a custom error'); // error message চেক করা
  });
});
```

এখানে:
- আমরা **supertest** লাইব্রেরি ব্যবহার করছি HTTP রিকোয়েস্টের মাধ্যমে আমাদের Express রাউট টেস্ট করতে।
- `/error` রাউটে GET রিকোয়েস্ট পাঠিয়ে এর **status** এবং **message** চেক করা হচ্ছে।

---

## ⏸️ 2. Refactoring the Code

**Refactoring** এর মাধ্যমে আমরা আমাদের কোডের গঠন এবং মান উন্নত করি, যাতে তা আরও পড়া এবং রক্ষণাবেক্ষণযোগ্য হয়। আমরা আমাদের কোডটি আরও দক্ষ, পরিষ্কার এবং সোজা বানাতে পারি।

### Refactor AppError Class

কাস্টম **AppError** ক্লাসটি রিফ্যাক্টর করতে পারি যাতে এটি আরও পরিষ্কার এবং টেস্টযোগ্য হয়।

```js
class AppError extends Error {
  constructor(message, statusCode = 500) {
    super(message);
    this.statusCode = statusCode;
    this.isOperational = true;
    Error.captureStackTrace(this, this.constructor);
  }
}

module.exports = AppError;
```

এখানে:
- **statusCode** ডিফল্ট মান হিসেবে 500 সেট করা হয়েছে, যাতে ব্যবহারকারীরা অযথা status কোড প্রদান না করেন।
- কোডটি আরো সরল এবং পরিষ্কার হয়েছে।

---

## ⏸️ 3. Refactor Centralized Error Handler

**Centralized Error Handler** রিফ্যাক্টর করার মাধ্যমে, আমরা একাধিক স্থান থেকে ত্রুটি হ্যান্ডলিং কে এক জায়গায় সংগঠিত করতে পারি।

```js
const AppError = require('./utils/appError');

const handleError = (err, req, res, next) => {
  const statusCode = err.isOperational ? err.statusCode : 500;
  const message = err.isOperational ? err.message : 'Something went wrong!';

  res.status(statusCode).json({
    status: 'error',
    message,
  });

  if (!err.isOperational) {
    console.error('ERROR 💥:', err);
  }
};

module.exports = handleError;
```

এখানে:
- আমরা কোডটিকে ছোট ও পরিষ্কার করেছি, এবং **statusCode** এবং **message** একসাথে হ্যান্ডলিং করেছি।
- **Operational errors** এবং **non-operational errors** এর মধ্যে পার্থক্য স্পষ্টভাবে করা হয়েছে।

---

## ⏸️ 4. Ensure Everything Works After Refactoring

রিফ্যাক্টর করার পর, আমাদের নিশ্চিত করতে হবে যে সবকিছু ঠিকভাবে কাজ করছে। এজন্য, আমরা **test cases** চালিয়ে দেখতে পারি।

```js
describe('Test Refactored Error Handling', () => {
  it('should return 500 for non-operational error', async () => {
    const res = await request(app).get('/non-operational-error'); // non-operational error রাউটে GET রিকোয়েস্ট
    expect(res.status).toBe(500); // 500 status code চেক করা
    expect(res.body.message).toBe('Something went wrong!'); // error message চেক করা
  });
});
```

এখানে:
- আমরা নিশ্চিত হচ্ছি যে **non-operational error** রিফ্যাক্টর করার পরও সঠিকভাবে হ্যান্ডল হচ্ছে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Error testing** এর মাধ্যমে কিভাবে ত্রুটির আচরণ নিশ্চিত করা যায়।
- **Code refactoring** এর মাধ্যমে কোডকে পরিষ্কার, দক্ষ এবং রক্ষণাবেক্ষণযোগ্য বানানো।
- কাস্টম **error classes** এবং **centralized error handler** রিফ্যাক্টর করার মাধ্যমে কোডের গঠন উন্নত করা।

আজকের দিনে আপনি শিখলেন কিভাবে ত্রুটির আচরণ টেস্ট করতে হয় এবং কোড রিফ্যাক্টরিং এর মাধ্যমে প্রজেক্টে উন্নতি আনা যায়। 🛠️🚀





# Day 42

✅ **আজকের দিনটি: Revision + mini-project with Zod**

আজকের দিনে আমরা **Zod** লাইব্রেরির সাথে একটি ছোট প্রোজেক্ট তৈরি করব। প্রথমে, আমরা যা শিখেছি তা রিভাইজ করব এবং তারপর **Zod** দিয়ে একটি ছোট প্রোজেক্ট তৈরি করব।

---

## ⏸️ 1. Zod লাইব্রেরি রিভিশন

**Zod** একটি **TypeScript-first schema validation** লাইব্রেরি, যা আমাদের ডেটার ভ্যালিডেশন খুব সহজভাবে করতে সাহায্য করে। এটি আমাদের ডেটার গঠন ও মান চেক করার জন্য ব্যবহার করা হয়। আমরা এর সাহায্যে **string**, **number**, **array**, **object** এবং অন্যান্য ধরনের স্কিমা তৈরি করতে পারি।

### Zod স্কিমা তৈরি করা

```js
const { z } = require('zod');

const userSchema = z.object({
  name: z.string().min(3, 'Name must be at least 3 characters long'),
  age: z.number().min(18, 'Age must be at least 18'),
  email: z.string().email('Invalid email format'),
});
```

এখানে:
- **name**: একটি স্ট্রিং হতে হবে এবং এর দৈর্ঘ্য কমপক্ষে ৩ ক্যারেক্টার হতে হবে।
- **age**: একটি নম্বর হতে হবে এবং কমপক্ষে ১৮ হতে হবে।
- **email**: একটি বৈধ ইমেইল হতে হবে।

---

## ⏸️ 2. Mini Project: User Registration with Zod

এখন, আমরা একটি ছোট **user registration** প্রোজেক্ট তৈরি করব যেখানে **Zod** এর মাধ্যমে ব্যবহারকারীর ইনপুট ভ্যালিডেশন করা হবে।

### Step 1: Express Setup

```js
const express = require('express');
const { z } = require('zod');
const app = express();
const port = 3000;

app.use(express.json());

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
```

এখানে:
- **Express** সার্ভার চালু করেছি এবং **JSON** রিকোয়েস্ট গ্রহণ করার জন্য **express.json()** ব্যবহার করছি।

### Step 2: User Registration Route

```js
app.post('/register', (req, res) => {
  const userSchema = z.object({
    name: z.string().min(3, 'Name must be at least 3 characters long'),
    age: z.number().min(18, 'Age must be at least 18'),
    email: z.string().email('Invalid email format'),
  });

  try {
    const userData = userSchema.parse(req.body); // ইনপুট ভ্যালিডেশন
    res.status(200).json({ message: 'User registered successfully', userData });
  } catch (err) {
    res.status(400).json({ error: err.errors }); // ত্রুটি হ্যান্ডলিং
  }
});
```

এখানে:
- **userSchema** দিয়ে ব্যবহারকারীর ইনপুট ভ্যালিডেট করছি।
- যদি ইনপুট সঠিক থাকে, তাহলে **200** status কোড সহ ব্যবহারকারীর ডেটা ফেরত দিচ্ছি।
- যদি ত্রুটি হয়, তবে **400** status কোড সহ ত্রুটির বার্তা পাঠানো হচ্ছে।

### Step 3: Testing the Route

এখন, আমরা Postman বা **curl** ব্যবহার করে এই রেজিস্ট্রেশন রাউট টেস্ট করতে পারি।

```bash
curl -X POST http://localhost:3000/register -H "Content-Type: application/json" -d '{"name": "John", "age": 20, "email": "john@example.com"}'
```

এখানে:
- **curl** কমান্ড ব্যবহার করে আমরা POST রিকোয়েস্ট পাঠাচ্ছি।
- যদি ইনপুট সঠিক হয়, তবে আমরা সফল বার্তা পাবো, অন্যথায় ত্রুটির বার্তা পাবো।

---

## ⏸️ 3. Review and Practice

আজকের দিনে আপনি যা শিখলেন:

- **Zod** এর মাধ্যমে ডেটা ভ্যালিডেশন কিভাবে করা যায় তা রিভিউ করা।
- **User Registration** এর জন্য একটি ছোট প্রোজেক্ট তৈরি করা, যেখানে **Zod** এর সাহায্যে ইনপুট ভ্যালিডেশন করা হয়েছে।
- ভ্যালিডেশন সফল হলে, ইউজারের ডেটা গ্রহণ করা এবং ত্রুটি ঘটলে তার বিস্তারিত বার্তা প্রদান করা।

আজকের দিনটি ছিল Zod নিয়ে কাজ করার এবং প্রোজেক্টে এটি প্রয়োগ করার দিন। এখন আপনি প্রস্তুত যে কোনো বড় প্রোজেক্টে Zod ব্যবহার করার জন্য! 🛠️🚀





