var admin = require("firebase-admin");

var serviceAccount = require("./serviceAccountKey.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL: "https://creditklick-d1c45-default-rtdb.firebaseio.com",
});

const phoneNumber = "+918130506284";
const otp = 123456;

async function isPhoneNumberTaken(phoneNumber) {
  try {
    const userRecord = await admin.auth().getUserByPhoneNumber(phoneNumber);
    return userRecord !== null;
  } catch (error) {
    if (error.code === "auth/user-not-found") {
      return false;
    } else {
      throw error;
    }
  }
}

async function signUpWithPhoneNumber({ phoneNumber, otp }) {
  if (!phoneNumber) return;
  try {
    const isTaken = await isPhoneNumberTaken(phoneNumber);

    if (!isTaken) {
      // Create or update user in Firebase Authentication
      const user = await admin.auth().createUser({ phoneNumber });
      console.log("User created:", user.uid);

      // Additional logic if needed

      return user;
    } else {
      throw new Error("Phone number is already taken");
    }
  } catch (error) {
    throw error;
  }
}

// signUpWithPhoneNumber({ phoneNumber })
//   .then((user) => {
//     console.log("User signed up:", user);
//   })
//   .catch((error) => {
//     console.error("Error signing up:", error.message);
//   });

async function signInWithPhoneNumber({ phoneNumber, otp }) {
  if (!phoneNumber) {
    throw new Error("Phone number and OTP are required");
  }

  try {
    // Assuming the user is already signed up and you have their user ID
    // const userId = "PJQqlrhkHeekFLTmN1WLUqkVO8a2";

    const isVerified = true;

    if (isVerified) {
      // Sign in the user using the Firebase Authentication SDK
      const user = await admin.auth().getUserByPhoneNumber(phoneNumber);
      console.log("User signed in:", user.uid);

      // Additional logic if needed

      return user;
    } else {
      throw new Error("OTP verification failed");
    }
  } catch (error) {
    console.error("Error:", error.message);
    throw error;
  }
}

signInWithPhoneNumber({ phoneNumber, otp })
  .then((user) => {
    console.log("User signed in:", user);
  })
  .catch((error) => {
    console.error("Error signing in:", error.message);
  });
