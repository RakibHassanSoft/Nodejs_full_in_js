# Day 29

✅ **আজকের দিনটি: User Model Setup & Registration**

আজকের দিনে, আমরা একটি User মডেল সেটআপ করব এবং একটি রেজিস্ট্রেশন ফিচার তৈরি করব। যেখানে ব্যবহারকারী তাদের তথ্য প্রদান করতে পারবেন এবং তা MongoDB ডাটাবেসে সংরক্ষণ হবে। Express এবং Mongoose ব্যবহার করে রেজিস্ট্রেশন API তৈরি করব।

---

## ⏸️ 1. User মডেল তৈরি

প্রথমে, আমাদের MongoDB ডাটাবেসে ব্যবহারকারী সংরক্ষণ করতে একটি User মডেল তৈরি করতে হবে। এখানে, আমরা ব্যবহারকারীর নাম, ইমেইল, পাসওয়ার্ড এবং রোল সংরক্ষণ করব।

### `models/User.js`

```js
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

// User মডেল তৈরি
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
  password: {
    type: String,
    required: true,
  },
  role: {
    type: String,
    enum: ['user', 'admin'],
    default: 'user',
  },
});

// পাসওয়ার্ড হ্যাশ করা
userSchema.pre('save', async function (next) {
  if (!this.isModified('password')) return next();
  
  const salt = await bcrypt.genSalt(10);
  this.password = await bcrypt.hash(this.password, salt);
  next();
});

// পাসওয়ার্ড যাচাই
userSchema.methods.matchPassword = async function (password) {
  return await bcrypt.compare(password, this.password);
};

const User = mongoose.model('User', userSchema);

module.exports = User;
```

এখানে:
- `name`: ব্যবহারকারীর নাম (স্ট্রিং)।
- `email`: ব্যবহারকারীর ইমেইল (স্ট্রিং), যা ইউনিক হবে।
- `password`: ব্যবহারকারীর পাসওয়ার্ড (স্ট্রিং), যা সুরক্ষিত রাখতে হ্যাশ করা হবে।
- `role`: ব্যবহারকারীর ভূমিকা (স্ট্রিং), ডিফল্ট হিসাবে 'user' থাকবে, তবে আপনি চাইলে এটি 'admin'ও হতে পারে।

---

## ⏸️ 2. রেজিস্ট্রেশন রাউট তৈরি

এখন, একটি রেজিস্ট্রেশন রাউট তৈরি করব, যেখানে ব্যবহারকারী তাদের তথ্য প্রদান করবেন এবং ডাটাবেসে সেই তথ্য সংরক্ষিত হবে।

### `routes/auth.js`

```js
const express = require('express');
const User = require('../models/User');
const router = express.Router();

// রেজিস্ট্রেশন রাউট
router.post('/register', async (req, res) => {
  const { name, email, password, role } = req.body;

  try {
    // চেক করুন, যদি ইমেইল ইতিমধ্যেই ডাটাবেসে থাকে
    const userExists = await User.findOne({ email });
    if (userExists) {
      return res.status(400).json({ message: 'ইমেইল ইতিমধ্যেই নিবন্ধিত' });
    }

    // নতুন ব্যবহারকারী তৈরি করা
    const user = new User({ name, email, password, role });
    await user.save();

    res.status(201).json({
      message: 'ব্যবহারকারী সফলভাবে নিবন্ধিত হয়েছে',
      user: { name: user.name, email: user.email, role: user.role },
    });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

module.exports = router;
```

এখানে:
- `/register`: একটি POST রাউট তৈরি করা হয়েছে, যেখানে ব্যবহারকারী নাম, ইমেইল, পাসওয়ার্ড এবং রোল প্রদান করবেন।
- **ব্যবহারকারী চেক**: যদি ইতিমধ্যে ডাটাবেসে ওই ইমেইল থাকে, তবে ত্রুটি বার্তা পাঠানো হবে।
- **ব্যবহারকারী সংরক্ষণ**: নতুন ব্যবহারকারী MongoDB ডাটাবেসে সংরক্ষিত হবে।

---

## ⏸️ 3. Express সার্ভারে রাউট যুক্ত করা

এখন আমাদের `server.js` ফাইলে এই রাউটটি যুক্ত করতে হবে যাতে এটি কার্যকরী হয়।

### `server.js`

```js
const express = require('express');
const mongoose = require('mongoose');
const dotenv = require('dotenv');
const bodyParser = require('body-parser');
const authRoutes = require('./routes/auth');

dotenv.config();

const app = express();
const port = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());

// MongoDB সংযোগ
mongoose.connect(process.env.DB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log('MongoDB connection error:', err));

// রাউট ব্যবহার
app.use('/api/auth', authRoutes);

// সার্ভার শুরু
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
```

এখানে:
- `/api/auth` রাউট ব্যবহার করা হয়েছে `auth.js` ফাইলের রেজিস্ট্রেশন রাউট সংযোগ করতে।

---

## ⏸️ 4. পরীক্ষা

এখন, আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে `/register` রাউটটি পরীক্ষা করতে পারেন।

### POST Request:
- **URL**: `http://localhost:3000/api/auth/register`
- **Body** (JSON):
  ```json
  {
    "name": "Rakib",
    "email": "rakib@example.com",
    "password": "password123",
    "role": "user"
  }
  ```

- **Response**:
  ```json
  {
    "message": "ব্যবহারকারী সফলভাবে নিবন্ধিত হয়েছে",
    "user": {
      "name": "Rakib",
      "email": "rakib@example.com",
      "role": "user"
    }
  }
  ```

---

## 📌 In Short:

- **User মডেল তৈরি**: MongoDB ডাটাবেসে ব্যবহারকারী সংরক্ষণ এবং পাসওয়ার্ড হ্যাশ করা।
- **রেজিস্ট্রেশন API তৈরি**: নতুন ব্যবহারকারী নিবন্ধন করার জন্য API তৈরি করা।
- **Express রাউটিং**: Express সার্ভারে API রাউট ব্যবহার করা।

আজকের প্রকল্পের মাধ্যমে আপনি ব্যবহারকারী নিবন্ধন ব্যবস্থা তৈরি করতে শিখলেন এবং MongoDB এর সাথে কাজ করার অভিজ্ঞতা অর্জন করেছেন। 🚀



# Day 30

✅ **আজকের দিনটি: Bcrypt for Hashing**

আজকের দিনে, আমরা `bcrypt` প্যাকেজ ব্যবহার করে পাসওয়ার্ড হ্যাশিং শিখব। এটি সুরক্ষিত পাসওয়ার্ড সংরক্ষণের একটি জনপ্রিয় পদ্ধতি। `bcrypt` পাসওয়ার্ড হ্যাশ করতে এবং যাচাই করতে সাহায্য করবে, যাতে ব্যবহারকারীর তথ্য সুরক্ষিত থাকে।

---

## ⏸️ 1. Bcrypt ইনস্টলেশন

প্রথমে, আমাদের `bcrypt` প্যাকেজটি ইনস্টল করতে হবে। এটি ইনস্টল করার জন্য নিচের কমান্ডটি ব্যবহার করুন:

```bash
npm install bcryptjs
```

`bcryptjs` একটি JavaScript ভিত্তিক প্যাকেজ, যা পাসওয়ার্ড হ্যাশ করতে এবং যাচাই করতে ব্যবহৃত হয়। আমরা এটি ব্যবহার করব পাসওয়ার্ড সুরক্ষিতভাবে সংরক্ষণ করতে এবং যাচাই করার জন্য।

---

## ⏸️ 2. পাসওয়ার্ড হ্যাশিং

এখন আমরা দেখব কীভাবে একটি পাসওয়ার্ড হ্যাশ করা হয়। মডেলটি যখন নতুন ব্যবহারকারী তৈরি করবে, তখন `bcrypt` ব্যবহার করে পাসওয়ার্ডটি হ্যাশ করা হবে, যাতে এটি ডাটাবেসে নিরাপদে সংরক্ষণ করা যায়।

### `models/User.js`

```js
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');

// User মডেল তৈরি
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
  password: {
    type: String,
    required: true,
  },
  role: {
    type: String,
    enum: ['user', 'admin'],
    default: 'user',
  },
});

// পাসওয়ার্ড হ্যাশ করা
userSchema.pre('save', async function (next) {
  if (!this.isModified('password')) return next();
  
  const salt = await bcrypt.genSalt(10); // Salt তৈরি করা
  this.password = await bcrypt.hash(this.password, salt); // পাসওয়ার্ড হ্যাশ করা
  next();
});

// পাসওয়ার্ড যাচাই
userSchema.methods.matchPassword = async function (password) {
  return await bcrypt.compare(password, this.password); // পাসওয়ার্ড তুলনা
};

const User = mongoose.model('User', userSchema);

module.exports = User;
```

এখানে:
- `bcrypt.genSalt(10)`: Salt তৈরি করা, যা হ্যাশিংয়ের জন্য প্রয়োজন।
- `bcrypt.hash()`: পাসওয়ার্ড হ্যাশ করা।
- `bcrypt.compare()`: ব্যবহারকারীর প্রদান করা পাসওয়ার্ড এবং ডাটাবেসে থাকা হ্যাশ করা পাসওয়ার্ডের তুলনা করা।

---

## ⏸️ 3. পাসওয়ার্ড যাচাই করা

ব্যবহারকারী যখন লগইন করবে, তখন আমরা যাচাই করব যে তাদের প্রদান করা পাসওয়ার্ডটি সঠিক কিনা। এটি করতে, আমরা `bcrypt.compare()` ব্যবহার করব।

### `routes/auth.js`

```js
const express = require('express');
const User = require('../models/User');
const router = express.Router();

// লগইন রাউট
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    // ব্যবহারকারী ইমেইল দিয়ে খোঁজা
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    // পাসওয়ার্ড যাচাই
    const isMatch = await user.matchPassword(password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    res.status(200).json({ message: 'লগইন সফল', user: { name: user.name, email: user.email, role: user.role } });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

module.exports = router;
```

এখানে:
- `matchPassword()` মেথড ব্যবহার করে পাসওয়ার্ড যাচাই করা হয়েছে। এটি `bcrypt.compare()` ব্যবহার করে, এবং যদি পাসওয়ার্ড সঠিক না হয় তবে ত্রুটি বার্তা পাঠানো হবে।

---

## ⏸️ 4. Express সার্ভারে রাউট যুক্ত করা

এখন আমাদের `server.js` ফাইলে লগইন রাউটটি যুক্ত করতে হবে যাতে এটি কার্যকরী হয়।

### `server.js`

```js
const express = require('express');
const mongoose = require('mongoose');
const dotenv = require('dotenv');
const bodyParser = require('body-parser');
const authRoutes = require('./routes/auth');

dotenv.config();

const app = express();
const port = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());

// MongoDB সংযোগ
mongoose.connect(process.env.DB_URI, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => console.log('MongoDB connected'))
  .catch(err => console.log('MongoDB connection error:', err));

// রাউট ব্যবহার
app.use('/api/auth', authRoutes);

// সার্ভার শুরু
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});
```

এখানে:
- `/api/auth/login` রাউটটি লগইন API হিসেবে ব্যবহৃত হবে।

---

## ⏸️ 5. পরীক্ষা

এখন, আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে `/login` রাউটটি পরীক্ষা করতে পারেন।

### POST Request:
- **URL**: `http://localhost:3000/api/auth/login`
- **Body** (JSON):
  ```json
  {
    "email": "rakib@example.com",
    "password": "password123"
  }
  ```

- **Response**:
  ```json
  {
    "message": "লগইন সফল",
    "user": {
      "name": "Rakib",
      "email": "rakib@example.com",
      "role": "user"
    }
  }
  ```

---

## 📌 In Shor:

- **Bcrypt ব্যবহার করে পাসওয়ার্ড হ্যাশিং**: সুরক্ষিত পাসওয়ার্ড সংরক্ষণ এবং যাচাই করতে `bcrypt` ব্যবহার করা।
- **পাসওয়ার্ড যাচাই**: লগইন API তৈরি করে ব্যবহারকারীর পাসওয়ার্ড যাচাই করা।

আজকের প্রকল্পের মাধ্যমে আপনি পাসওয়ার্ড হ্যাশিং এবং যাচাই করার প্রক্রিয়া শিখলেন এবং `bcrypt` ব্যবহার করার অভিজ্ঞতা অর্জন করেছেন। 🚀




# Day 31

✅ **আজকের দিনটি: JWT Creation & Verification**

আজকের দিনে, আমরা JSON Web Tokens (JWT) ব্যবহার করে authentication ব্যবস্থা তৈরি করব। JWT ব্যবহার করলে, আপনি নিরাপদভাবে তথ্য এক্সচেঞ্জ করতে পারেন। এটি সাধারণত ব্যবহারকারীর সেশন ধরে রাখার জন্য ব্যবহার করা হয়। JWT একটি এনক্রিপ্টেড টোকেন, যা সার্ভার এবং ক্লায়েন্টের মধ্যে সুরক্ষিতভাবে তথ্য ট্রান্সফার করতে সাহায্য করে।

---

## ⏸️ 1. JWT ইনস্টলেশন

প্রথমে, JWT ব্যবহারের জন্য `jsonwebtoken` প্যাকেজটি ইনস্টল করতে হবে।

```bash
npm install jsonwebtoken
```

`jsonwebtoken` একটি Node.js প্যাকেজ যা JWT টোকেন তৈরি এবং যাচাই করার জন্য ব্যবহৃত হয়।

---

## ⏸️ 2. JWT টোকেন তৈরি করা

ব্যবহারকারী লগইন হলে, সার্ভার একটি JWT টোকেন তৈরি করবে যা ব্যবহারকারীকে সুরক্ষিতভাবে প্রমাণিত করে। আমরা `jsonwebtoken` ব্যবহার করে টোকেন তৈরি করব এবং এটি ক্লায়েন্টকে পাঠাবো।

### `models/User.js`

```js
const jwt = require('jsonwebtoken');

// User মডেল
userSchema.methods.generateAuthToken = function () {
  const token = jwt.sign({ _id: this._id, email: this.email }, process.env.JWT_SECRET, { expiresIn: '1h' });
  return token;
};
```

এখানে:
- `jwt.sign()` পদ্ধতিটি একটি টোকেন তৈরি করে।
- প্রথম আর্গুমেন্টে আমরা ব্যবহারকারীর `_id` এবং `email` পাঠাচ্ছি, যেগুলি টোকেনের মধ্যে সংরক্ষিত থাকবে।
- দ্বিতীয় আর্গুমেন্ট হল `JWT_SECRET` যা টোকেনটি এনক্রিপ্ট করতে ব্যবহৃত হয়।
- `expiresIn: '1h'` সেটিংয়ের মাধ্যমে টোকেনের মেয়াদ এক ঘণ্টা।

---

## ⏸️ 3. JWT টোকেন যাচাই করা

ব্যবহারকারী যদি লগইন করে, আমরা টোকেনটি ক্লায়েন্টের কাছে পাঠাবো। পরবর্তী যে কোন API রিকোয়েস্টের সময়, ক্লায়েন্ট সেই টোকেনটি পাঠাবে এবং সার্ভার এটি যাচাই করবে।

### `middleware/auth.js`

```js
const jwt = require('jsonwebtoken');

const auth = (req, res, next) => {
  const token = req.header('Authorization').replace('Bearer ', '');
  
  if (!token) {
    return res.status(401).send({ message: 'Access denied, token not provided' });
  }

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    req.user = decoded;
    next();
  } catch (error) {
    res.status(400).send({ message: 'Invalid token' });
  }
};

module.exports = auth;
```

এখানে:
- `jwt.verify()` টোকেন যাচাই করতে ব্যবহৃত হয়। এটি টোকেনের সত্যতা যাচাই করে এবং যদি টোকেন সঠিক হয়, তাহলে এটি ডিকোডেড তথ্য ফেরত দেয়।
- যদি টোকেনটি সঠিক না হয়, তাহলে একটি ত্রুটি বার্তা পাঠানো হয়।

---

## ⏸️ 4. JWT টোকেন ব্যবহার

এখন আমরা একটি `login` রাউট তৈরি করবো যা ব্যবহারকারী সফলভাবে লগইন করলে JWT টোকেন প্রদান করবে।

### `routes/auth.js`

```js
const express = require('express');
const User = require('../models/User');
const router = express.Router();

// লগইন রাউট
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const isMatch = await user.matchPassword(password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    const token = user.generateAuthToken();  // টোকেন তৈরি করা
    res.status(200).json({ message: 'লগইন সফল', token });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

module.exports = router;
```

এখানে:
- `generateAuthToken()` মেথড ব্যবহার করে টোকেন তৈরি করা হচ্ছে এবং সেটি ব্যবহারকারীকে ফেরত দেওয়া হচ্ছে।

---

## ⏸️ 5. JWT দিয়ে রক্ষিত রাউট

যেকোনো সুরক্ষিত রাউটের জন্য, আমরা JWT যাচাই করার জন্য `auth` middleware ব্যবহার করব।

### `routes/protected.js`

```js
const express = require('express');
const auth = require('../middleware/auth');
const router = express.Router();

// সুরক্ষিত রাউট
router.get('/protected', auth, (req, res) => {
  res.status(200).send({ message: 'এই রাউটে অ্যাক্সেস পেয়েছেন', user: req.user });
});

module.exports = router;
```

এখানে:
- `auth` middleware ব্যবহার করে JWT টোকেন যাচাই করা হচ্ছে।
- যদি টোকেন সঠিক হয়, তাহলে রাউটটি অ্যাক্সেস করা যাবে, অন্যথায় ত্রুটি বার্তা পাঠানো হবে।

---

## ⏸️ 6. পরীক্ষা

এখন, আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে `/login` এবং `/protected` রাউটগুলি পরীক্ষা করতে পারেন।

### POST Request:
- **URL**: `http://localhost:3000/api/auth/login`
- **Body** (JSON):
  ```json
  {
    "email": "rakib@example.com",
    "password": "password123"
  }
  ```

- **Response** (Login Success):
  ```json
  {
    "message": "লগইন সফল",
    "token": "JWT_TOKEN_HERE"
  }
  ```

### GET Request (Protected Route):
- **URL**: `http://localhost:3000/api/protected/protected`
- **Headers**:
  ```json
  {
    "Authorization": "Bearer JWT_TOKEN_HERE"
  }
  ```

- **Response** (Access Granted):
  ```json
  {
    "message": "এই রাউটে অ্যাক্সেস পেয়েছেন",
    "user": {
      "_id": "USER_ID",
      "email": "rakib@example.com"
    }
  }
  ```

---

## 📌 In Short:

- **JWT টোকেন তৈরি ও যাচাই**: ব্যবহারকারীর লগইন হলে JWT টোকেন তৈরি এবং রক্ষিত রাউটে এটি যাচাই করা।
- **JWT middleware**: নিরাপদ রাউট অ্যাক্সেসের জন্য JWT টোকেন যাচাই করা।

আজকের প্রকল্পে আপনি JWT ব্যবহারের মাধ্যমে নিরাপদ অথেনটিকেশন ব্যবস্থা তৈরি করেছেন এবং এটি ক্লায়েন্ট-সার্ভার যোগাযোগের মধ্যে সুরক্ষা এনেছে। 🚀




# Day 32

✅ **আজকের দিনটি: Login + Protect Routes**

আজকের দিনে, আমরা JWT টোকেন ব্যবহার করে লগইন ব্যবস্থা তৈরি করবো এবং রাউটগুলোকে সুরক্ষিত (protected) রাখব। এর মাধ্যমে, আপনি শুধু লগইন করা ব্যবহারকারীদের জন্য নির্দিষ্ট রাউট অ্যাক্সেসযোগ্য করতে পারবেন। 

---

## ⏸️ 1. লগইন ফিচার তৈরি করা

প্রথমে, ব্যবহারকারীকে লগইন করার জন্য একটি API তৈরি করবো। এখানে আমরা `email` এবং `password` ব্যবহার করে লগইন করবো। সফল লগইনের পর একটি JWT টোকেন ফিরিয়ে দেওয়া হবে যা ব্যবহারকারীকে পরবর্তীতে অন্যান্য সুরক্ষিত রাউটে প্রবেশ করতে সাহায্য করবে।

### `models/User.js`

```js
const jwt = require('jsonwebtoken');

// User মডেল
userSchema.methods.generateAuthToken = function () {
  const token = jwt.sign({ _id: this._id, email: this.email }, process.env.JWT_SECRET, { expiresIn: '1h' });
  return token;
};
```

এখানে:
- `generateAuthToken()` মেথড ব্যবহারকারীর `_id` এবং `email` নিয়ে JWT টোকেন তৈরি করছে। টোকেনটি 1 ঘণ্টা পর্যন্ত বৈধ থাকবে।

---

## ⏸️ 2. লগইন রাউট তৈরি করা

আমরা একটি POST রাউট তৈরি করবো যা ব্যবহারকারীকে লগইন করতে সাহায্য করবে এবং JWT টোকেন প্রদান করবে।

### `routes/auth.js`

```js
const express = require('express');
const User = require('../models/User');
const router = express.Router();

// লগইন রাউট
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const isMatch = await user.matchPassword(password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    const token = user.generateAuthToken();  // টোকেন তৈরি করা
    res.status(200).json({ message: 'লগইন সফল', token });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

module.exports = router;
```

এখানে:
- ব্যবহারকারীর `email` এবং `password` যাচাই করা হচ্ছে। যদি সঠিক হয়, তবে JWT টোকেন তৈরি করা হচ্ছে এবং ক্লায়েন্টকে পাঠানো হচ্ছে।

---

## ⏸️ 3. রাউট সুরক্ষিত করা

এখন আমরা একটি middleware তৈরি করবো যা JWT টোকেন যাচাই করবে এবং রাউটটি সুরক্ষিত করবে। এটি নিশ্চিত করবে যে শুধু লগইন করা ব্যবহারকারীরাই সুরক্ষিত রাউট অ্যাক্সেস করতে পারবে।

### `middleware/auth.js`

```js
const jwt = require('jsonwebtoken');

const auth = (req, res, next) => {
  const token = req.header('Authorization').replace('Bearer ', '');
  
  if (!token) {
    return res.status(401).send({ message: 'অ্যাক্সেস প্রত্যাখ্যান, টোকেন প্রদান করা হয়নি' });
  }

  try {
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    req.user = decoded;
    next();
  } catch (error) {
    res.status(400).send({ message: 'অকার্যকর টোকেন' });
  }
};

module.exports = auth;
```

এখানে:
- `Authorization` হেডারে প্রাপ্ত টোকেনটি যাচাই করা হচ্ছে।
- যদি টোকেন সঠিক হয়, তবে `req.user` তে ডিকোডেড তথ্য সেট করা হচ্ছে এবং পরবর্তী রাউটে যাওয়া হচ্ছে।

---

## ⏸️ 4. সুরক্ষিত রাউট তৈরি করা

এখন আমরা একটি GET রাউট তৈরি করবো যা শুধুমাত্র লগইন করা ব্যবহারকারীরা অ্যাক্সেস করতে পারবে। এই রাউটে `auth` middleware ব্যবহার করা হবে যা JWT যাচাই করবে।

### `routes/protected.js`

```js
const express = require('express');
const auth = require('../middleware/auth');
const router = express.Router();

// সুরক্ষিত রাউট
router.get('/protected', auth, (req, res) => {
  res.status(200).send({ message: 'এই রাউটে অ্যাক্সেস পেয়েছেন', user: req.user });
});

module.exports = router;
```

এখানে:
- `auth` middleware রাউটে যুক্ত করা হয়েছে যা JWT যাচাই করে এবং ব্যবহারকারীকে অ্যাক্সেস দেয়।

---

## ⏸️ 5. লগইন এবং সুরক্ষিত রাউট পরীক্ষা করা

এখন, আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে `/login` এবং `/protected` রাউটগুলি পরীক্ষা করতে পারেন।

### POST Request (Login):
- **URL**: `http://localhost:3000/api/auth/login`
- **Body** (JSON):
  ```json
  {
    "email": "rakib@example.com",
    "password": "password123"
  }
  ```

- **Response** (Login Success):
  ```json
  {
    "message": "লগইন সফল",
    "token": "JWT_TOKEN_HERE"
  }
  ```

### GET Request (Protected Route):
- **URL**: `http://localhost:3000/api/protected/protected`
- **Headers**:
  ```json
  {
    "Authorization": "Bearer JWT_TOKEN_HERE"
  }
  ```

- **Response** (Access Granted):
  ```json
  {
    "message": "এই রাউটে অ্যাক্সেস পেয়েছেন",
    "user": {
      "_id": "USER_ID",
      "email": "rakib@example.com"
    }
  }
  ```

---

## 📌 In Short:

- **লগইন সিস্টেম**: JWT টোকেন ব্যবহার করে লগইন ব্যবস্থা তৈরি করা।
- **সুরক্ষিত রাউট**: JWT যাচাই করে রাউট সুরক্ষা নিশ্চিত করা এবং শুধুমাত্র লগইন করা ব্যবহারকারীদের জন্য রাউট অ্যাক্সেসযোগ্য করা।

আজকের প্রকল্পে আপনি JWT ব্যবহার করে লগইন ব্যবস্থা এবং সুরক্ষিত রাউট তৈরি করেছেন। আপনার অ্যাপ্লিকেশন এখন নিরাপদভাবে ব্যবহারকারীর সেশন পরিচালনা করতে সক্ষম। 🚀




# Day 33

✅ **আজকের দিনটি: Refresh Token System**

আজকের দিনে, আমরা **Refresh Token System** তৈরি করবো, যা JWT টোকেনের মেয়াদ শেষ হওয়ার পরেও ব্যবহারকারীদের অ্যাক্সেস পুনরায় নিশ্চিত করতে সাহায্য করবে। Refresh token ব্যবহারকারীকে নতুন access token পেতে সহায়তা করবে এবং এটি ব্যবহারকারীকে লগ আউট না করেই নতুন টোকেন পেতে সক্ষম করবে।

---

## ⏸️ 1. Refresh Token কি?

Refresh token একটি বিশেষ ধরনের টোকেন যা সাধারণত একটি দীর্ঘ মেয়াদী থাকে। এটি শুধুমাত্র ব্যবহারকারীকে নতুন access token পাওয়ার সুযোগ দেয়, কিন্তু সরাসরি ব্যবহারকারীর অ্যাক্সেস কন্ট্রোল করে না। যখন **access token** মেয়াদ শেষ হয়ে যায়, তখন **refresh token** ব্যবহার করে একটি নতুন access token তৈরি করা যায়।

---

## ⏸️ 2. Refresh Token তৈরি ও সংরক্ষণ

প্রথমে, আমরা একটি নতুন refresh token তৈরি করবো এবং সেটি ব্যবহারকারীর ডেটাবেসে সংরক্ষণ করবো।

### `models/User.js`

```js
const jwt = require('jsonwebtoken');

// User মডেল
userSchema.methods.generateAuthToken = function () {
  const token = jwt.sign({ _id: this._id, email: this.email }, process.env.JWT_SECRET, { expiresIn: '1h' });
  return token;
};

// Refresh token তৈরি করা
userSchema.methods.generateRefreshToken = function () {
  const refreshToken = jwt.sign({ _id: this._id, email: this.email }, process.env.JWT_SECRET, { expiresIn: '7d' });
  return refreshToken;
};
```

এখানে:
- `generateRefreshToken()` মেথডটি একটি নতুন refresh token তৈরি করছে, যার মেয়াদ 7 দিন হবে।

---

## ⏸️ 3. Refresh Token রাউট তৈরি করা

এখন আমরা একটি রাউট তৈরি করবো, যা ব্যবহারকারীদের **refresh token** প্রদান করবে, যাতে তারা পুরোনো **access token** এর মেয়াদ শেষ হলে একটি নতুন token পেতে পারে।

### `routes/auth.js`

```js
const express = require('express');
const User = require('../models/User');
const jwt = require('jsonwebtoken');
const router = express.Router();

// Refresh Token রাউট
router.post('/refresh-token', async (req, res) => {
  const { refreshToken } = req.body;
  
  if (!refreshToken) {
    return res.status(401).json({ message: 'Refresh token প্রদান করা হয়নি' });
  }

  try {
    const decoded = jwt.verify(refreshToken, process.env.JWT_SECRET);
    const user = await User.findOne({ _id: decoded._id });

    if (!user) {
      return res.status(404).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const newAccessToken = user.generateAuthToken(); // নতুন access token তৈরি করা
    res.status(200).json({ accessToken: newAccessToken });
  } catch (error) {
    res.status(400).json({ message: 'অকার্যকর refresh token' });
  }
});

module.exports = router;
```

এখানে:
- `refresh-token` রাউটে `refreshToken` প্যারামিটার চাওয়া হচ্ছে। এটি যাচাই করার পর একটি নতুন access token তৈরি করা হচ্ছে।

---

## ⏸️ 4. Refresh Token ব্যবহার করে লগইন

আমরা একটি POST রাউট তৈরি করবো, যেখানে ব্যবহারকারী প্রথমে লগইন করার সময় দুটি টোকেন পাবে: একটি access token এবং একটি refresh token।

### `routes/auth.js`

```js
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const isMatch = await user.matchPassword(password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    const accessToken = user.generateAuthToken();
    const refreshToken = user.generateRefreshToken(); // Refresh token তৈরি করা

    res.status(200).json({ message: 'লগইন সফল', accessToken, refreshToken });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});
```

এখানে:
- `login` রাউটটি ব্যবহৃত হয় নতুন **access token** এবং **refresh token** প্রদান করার জন্য।

---

## ⏸️ 5. Token Refresh Flow

1. **Login**: ব্যবহারকারী প্রথমে লগইন করে access token এবং refresh token পায়।
2. **Token Expiry**: যখন access token এর মেয়াদ শেষ হয়ে যায়, ব্যবহারকারী refresh token দিয়ে নতুন access token পেতে পারে।
3. **New Access Token**: `POST /refresh-token` রাউটে refresh token পাঠিয়ে নতুন access token পাওয়া যায়।

---

## ⏸️ 6. লগইন ও Refresh Token পরীক্ষা করা

এখন আপনি Postman বা যেকোনো API টেস্টিং টুল ব্যবহার করে `/login` এবং `/refresh-token` রাউটগুলো পরীক্ষা করতে পারেন।

### POST Request (Login):
- **URL**: `http://localhost:3000/api/auth/login`
- **Body** (JSON):
  ```json
  {
    "email": "rakib@example.com",
    "password": "password123"
  }
  ```

- **Response** (Login Success):
  ```json
  {
    "message": "লগইন সফল",
    "accessToken": "NEW_ACCESS_TOKEN_HERE",
    "refreshToken": "NEW_REFRESH_TOKEN_HERE"
  }
  ```

### POST Request (Refresh Token):
- **URL**: `http://localhost:3000/api/auth/refresh-token`
- **Body** (JSON):
  ```json
  {
    "refreshToken": "EXISTING_REFRESH_TOKEN_HERE"
  }
  ```

- **Response** (New Access Token):
  ```json
  {
    "accessToken": "NEW_ACCESS_TOKEN_HERE"
  }
  ```

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Refresh Token System**: Refresh token তৈরি এবং সেটি ব্যবহার করে নতুন access token পাওয়া।
- **Security**: Refresh token ব্যবহারের মাধ্যমে আপনি নিরাপদভাবে ব্যবহারকারীদের দীর্ঘকালীন সেশন পরিচালনা করতে পারবেন, তাদের পুনরায় লগইন না করিয়ে।

আজকের প্রকল্পে আপনি JWT এর সাহায্যে Refresh token সিস্টেম তৈরি করেছেন, যা নিরাপদ এবং কার্যকর সেশন ম্যানেজমেন্ট নিশ্চিত করবে। 🚀





# Day 34

✅ **আজকের দিনটি: JWT Store in HTTP-only Cookie**

আজকের দিনে আমরা শিখবো কীভাবে **JWT (JSON Web Token)** কে **HTTP-only Cookie**-তে সংরক্ষণ করা যায়। এই পদ্ধতিটি নিরাপত্তা বৃদ্ধির জন্য ব্যবহৃত হয়, যেখানে টোকেন ক্লায়েন্ট সাইডের JavaScript থেকে অ্যাক্সেস করা যায় না, এটি কেবল সার্ভার সাইডে ব্যবহৃত হবে। এর ফলে XSS (Cross-Site Scripting) আক্রমণ থেকে রক্ষা পাওয়া যায়।

---

## ⏸️ 1. HTTP-only Cookie কি?

**HTTP-only Cookie** একটি বিশেষ ধরনের cookie যা **JavaScript** এর মাধ্যমে অ্যাক্সেস করা যায় না, শুধুমাত্র HTTP রিকোয়েস্টের মাধ্যমে এটি সার্ভারে পাঠানো হয়। এটি নিরাপদ এবং হ্যাকারদের জন্য সমস্যার সৃষ্টি করতে পারে না, কারণ তারা JavaScript দিয়ে এই cookie তে অ্যাক্সেস করতে পারবে না।

---

## ⏸️ 2. JWT কে HTTP-only Cookie তে সংরক্ষণ

প্রথমে, আমরা একটি JWT টোকেন তৈরি করবো এবং সেটি **HTTP-only Cookie** হিসেবে ক্লায়েন্টে পাঠাবো। যখন ব্যবহারকারী লগইন করবে, তখন আমরা টোকেনটি HTTP-only Cookie তে সেট করবো।

### `routes/auth.js`

```js
const express = require('express');
const jwt = require('jsonwebtoken');
const User = require('../models/User');
const router = express.Router();

// লগইন রাউট
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const isMatch = await user.matchPassword(password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    const accessToken = user.generateAuthToken();
    const refreshToken = user.generateRefreshToken(); // Refresh token তৈরি করা

    // HTTP-only cookie তে JWT টোকেন সেট করা
    res.cookie('accessToken', accessToken, {
      httpOnly: true, // cookie-টি JavaScript দিয়ে অ্যাক্সেসযোগ্য হবে না
      secure: process.env.NODE_ENV === 'production', // Production মোডে সুরক্ষিত সংযোগ (https) হবে
      maxAge: 60 * 60 * 24 * 7 * 1000, // cookie এর মেয়াদ 7 দিন
    });

    res.status(200).json({ message: 'লগইন সফল', refreshToken });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

module.exports = router;
```

এখানে:
- আমরা **access token** HTTP-only cookie তে সংরক্ষণ করছি।
- `httpOnly: true` নিশ্চিত করে যে cookie তে JavaScript দিয়ে অ্যাক্সেস করা যাবে না।
- `secure: process.env.NODE_ENV === 'production'` নিশ্চিত করে যে cookie শুধুমাত্র নিরাপদ (HTTPS) পরিবেশে পাঠানো হবে।

---

## ⏸️ 3. Token Verification with HTTP-only Cookie

এখন, আমরা একটি রাউট তৈরি করবো যা HTTP-only cookie থেকে JWT টোকেন বের করবে এবং যাচাই করবে। ব্যবহারকারী যখন তার token ব্যবহার করবে, তখন এই cookie থেকে টোকেন পড়া হবে।

### `middlewares/auth.js`

```js
const jwt = require('jsonwebtoken');

const authenticateToken = (req, res, next) => {
  const token = req.cookies.accessToken; // HTTP-only cookie থেকে JWT টোকেন পড়া

  if (!token) {
    return res.status(401).json({ message: 'অনুগ্রহ করে লগইন করুন' });
  }

  jwt.verify(token, process.env.JWT_SECRET, (err, decoded) => {
    if (err) {
      return res.status(403).json({ message: 'অকার্যকর টোকেন' });
    }
    req.user = decoded;
    next();
  });
};

module.exports = authenticateToken;
```

এখানে:
- আমরা `req.cookies.accessToken` ব্যবহার করে HTTP-only cookie থেকে JWT টোকেন গ্রহণ করছি।
- টোকেন যাচাই করার পর ব্যবহারকারীর তথ্য `req.user` এ সংরক্ষণ করা হচ্ছে, যাতে পরবর্তী মেথডে অ্যাক্সেস করা যায়।

---

## ⏸️ 4. Token Verification Middleware ব্যবহার

এখন আমরা আমাদের secured রাউটগুলোতে `authenticateToken` middleware ব্যবহার করবো, যাতে যেকোনো প্রটেক্টেড রাউটে ব্যবহারকারী শুধুমাত্র তখনই প্রবেশ করতে পারে যখন তার টোকেন বৈধ থাকে।

### `routes/protected.js`

```js
const express = require('express');
const authenticateToken = require('../middlewares/auth');
const router = express.Router();

// Protected Route Example
router.get('/protected', authenticateToken, (req, res) => {
  res.status(200).json({ message: 'এটি একটি সুরক্ষিত রাউট', user: req.user });
});

module.exports = router;
```

এখানে:
- `authenticateToken` middleware ব্যবহার করা হয়েছে, যা নিশ্চিত করে যে শুধু বৈধ টোকেনধারী ব্যবহারকারীরাই সুরক্ষিত রাউট অ্যাক্সেস করতে পারবে।

---

## ⏸️ 5. Cookie Delete (Logout) করা

যখন ব্যবহারকারী লগআউট করবে, তখন আমরা তাদের cookie মুছে দেবো। এটি ব্যবহারকারীদের সেশন শেষ করার জন্য সহায়ক হবে।

### `routes/auth.js`

```js
router.post('/logout', (req, res) => {
  res.clearCookie('accessToken'); // Cookie মুছে ফেলা
  res.status(200).json({ message: 'লগআউট সফল' });
});
```

এখানে:
- `res.clearCookie('accessToken')` ব্যবহার করে আমরা `accessToken` cookie মুছে দিচ্ছি, যার মাধ্যমে ব্যবহারকারী লগআউট হবে।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **JWT টোকেনকে HTTP-only Cookie তে সংরক্ষণ করা**: নিরাপদভাবে টোকেন সংরক্ষণ করা এবং তা শুধুমাত্র সার্ভার সাইডে ব্যবহৃত হওয়া।
- **Token Verification**: HTTP-only cookie থেকে টোকেন নিয়ে তা যাচাই করা।
- **Security**: JavaScript থেকে টোকেন অ্যাক্সেস না হওয়ার ফলে XSS আক্রমণ থেকে সুরক্ষা পাওয়া।

আজকের প্রকল্পে আপনি JWT টোকেনকে HTTP-only cookie তে সংরক্ষণ এবং সুরক্ষিত রাউটগুলোর জন্য তা যাচাই করতে শিখেছেন। 🚀






# Day 35

✅ **আজকের দিনটি: Auth System সম্পূর্ণ করা এবং টেস্টিং**

আজকের দিনে আমরা **Auth System** সম্পূর্ণ করবো এবং এর সমস্ত ফাংশনালিটি পরীক্ষা (testing) করবো। আমরা নিশ্চিত হবো যে সিস্টেমটি সঠিকভাবে কাজ করছে এবং নিরাপত্তা নিশ্চিত করা হয়েছে।

---

## ⏸️ 1. Authentication System সম্পূর্ণ করা

আজকের দিনে আমরা **JWT authentication** সিস্টেম সম্পূর্ণ করবো এবং নিশ্চিত করবো যে রেজিস্ট্রেশন, লগইন, এবং সুরক্ষিত রাউটগুলো সঠিকভাবে কাজ করছে। আমরা এর মধ্যে থাকবে:

1. **User Registration** (পাসওয়ার্ড হ্যাশিংসহ)
2. **User Login** (JWT তৈরি)
3. **Token Storage** (HTTP-only Cookie তে টোকেন সংরক্ষণ)
4. **Token Verification** (প্রতিটি রিকোয়েস্টে টোকেন যাচাই করা)
5. **Logout** (টোকেন মুছে ফেলা)

### `routes/auth.js`

```js
const express = require('express');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');
const User = require('../models/User');
const router = express.Router();

// রেজিস্ট্রেশন রাউট
router.post('/register', async (req, res) => {
  const { email, password } = req.body;

  try {
    const userExists = await User.findOne({ email });
    if (userExists) {
      return res.status(400).json({ message: 'ইমেইল ইতিমধ্যে রেজিস্টার করা হয়েছে' });
    }

    const hashedPassword = await bcrypt.hash(password, 10);
    const newUser = new User({ email, password: hashedPassword });
    await newUser.save();
    res.status(201).json({ message: 'রেজিস্ট্রেশন সফল' });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

// লগইন রাউট
router.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    const user = await User.findOne({ email });
    if (!user) {
      return res.status(400).json({ message: 'ব্যবহারকারী পাওয়া যায়নি' });
    }

    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) {
      return res.status(400).json({ message: 'পাসওয়ার্ড সঠিক নয়' });
    }

    const token = jwt.sign({ userId: user._id }, process.env.JWT_SECRET, { expiresIn: '1h' });
    res.cookie('accessToken', token, {
      httpOnly: true,
      secure: process.env.NODE_ENV === 'production',
      maxAge: 60 * 60 * 1000, // 1 hour
    });

    res.status(200).json({ message: 'লগইন সফল' });
  } catch (error) {
    res.status(500).json({ message: 'সার্ভার ত্রুটি', error: error.message });
  }
});

// লগআউট রাউট
router.post('/logout', (req, res) => {
  res.clearCookie('accessToken');
  res.status(200).json({ message: 'লগআউট সফল' });
});

module.exports = router;
```

এখানে:
- রেজিস্ট্রেশন, লগইন এবং লগআউট রাউটগুলোর মধ্যে নিরাপত্তা নিশ্চিত করা হয়েছে।
- লগইন সফল হলে JWT টোকেন HTTP-only Cookie তে সংরক্ষণ করা হয়।

---

## ⏸️ 2. Token Verification Middleware

এই মেটোডটি প্রটেক্টেড রাউটগুলোতে টোকেন যাচাই করতে ব্যবহৃত হবে।

### `middlewares/auth.js`

```js
const jwt = require('jsonwebtoken');

const authenticateToken = (req, res, next) => {
  const token = req.cookies.accessToken;

  if (!token) {
    return res.status(401).json({ message: 'অনুগ্রহ করে লগইন করুন' });
  }

  jwt.verify(token, process.env.JWT_SECRET, (err, decoded) => {
    if (err) {
      return res.status(403).json({ message: 'অকার্যকর টোকেন' });
    }
    req.user = decoded;
    next();
  });
};

module.exports = authenticateToken;
```

এখানে:
- আমরা `authenticateToken` middleware ব্যবহার করছি যেটি HTTP-only cookie থেকে টোকেন বের করে যাচাই করে।

---

## ⏸️ 3. Protected Routes

এই রাউটগুলো শুধুমাত্র তখনই অ্যাক্সেস করা যাবে যখন ব্যবহারকারীর টোকেন বৈধ থাকবে।

### `routes/protected.js`

```js
const express = require('express');
const authenticateToken = require('../middlewares/auth');
const router = express.Router();

router.get('/protected', authenticateToken, (req, res) => {
  res.status(200).json({ message: 'এটি একটি সুরক্ষিত রাউট', user: req.user });
});

module.exports = router;
```

এখানে:
- `authenticateToken` middleware ব্যবহার করে আমরা রাউটটিকে সুরক্ষিত করেছি।

---

## ⏸️ 4. Testing

এখন, আপনি **Postman** বা **Insomnia** ব্যবহার করে পুরো Auth System টেস্ট করতে পারেন। নিম্নলিখিত টেস্টগুলো করতে হবে:

1. **POST /register**: নতুন ব্যবহারকারী রেজিস্ট্রেশন।
2. **POST /login**: লগইন এবং টোকেন পাওয়ার জন্য।
3. **GET /protected**: সুরক্ষিত রাউট অ্যাক্সেস করার জন্য। (টোকেন সহ রিকোয়েস্ট পাঠানো)
4. **POST /logout**: লগআউট এবং টোকেন মুছে ফেলা।

---

## 📌 সংক্ষেপে, আজকের দিনে আপনি শিখলেন:

- **Auth System সম্পূর্ণ করা**: রেজিস্ট্রেশন, লগইন, লগআউট এবং সুরক্ষিত রাউটগুলির সব ফিচার বাস্তবায়ন করা।
- **Token Verification Middleware**: HTTP-only cookie থেকে টোকেন যাচাই করা এবং সুরক্ষিত রাউটে অ্যাক্সেস দেয়া।
- **Testing**: Postman বা Insomnia ব্যবহার করে Auth System টেস্টিং।

আজকের দিনে আপনার Auth System প্রস্তুত এবং সঠিকভাবে টেস্ট করা হয়ে গেছে! 🚀





