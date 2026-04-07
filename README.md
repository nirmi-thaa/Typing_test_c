# Typing_test_c
A C-based typing test program that measures typing accuracy, speed (WPM), and time taken using fixed sentences or randomly generated words.

# ⌨️ Typing Speed Test (C)

A simple C-based program to measure your **typing speed**, **accuracy**, and **time taken** using either a fixed sentence or randomly generated words.

## 🚀 Features

* 📊 Calculates **Typing Speed (WPM)**
* 🎯 Measures **Accuracy (%)**
* ⏱️ Tracks **Time Taken**
* 🔤 Practice with:

  * Fixed sentence
  * Random generated words
* 💾 Saves user performance data to file
* 🔍 Search previous records by username

---

## 🛠️ Technologies Used

* C Programming
* Standard Libraries:

  * stdio.h
  * string.h
  * time.h
  * stdlib.h

---

## 📂 Project Structure


typing-test-c/
│── typing_test.c
│── data.txt        # Stores user results
│── README.md


---

## ▶️ How to Run

### Step 1: Compile the code


gcc typing_test.c -o test

### Step 2: Run the program


./test



## 📋 Menu Options

1. Type test (fixed sentence)
2. Random words typing test
3. Show existing data
4. Exit


## 💡 How It Works

* The program displays a sentence or random word.
* You type the given text.
* It calculates:

  * Time taken
  * Accuracy (character match)
  * Words per minute (WPM)
* Results are saved for future reference.

---

## 📊 Example Output

######## RESULTS ########
Time Taken: 12.00 seconds
Accuracy: 95.00%
Typing Speed: 40.00 WPM

---

## ⚠️ Notes

* Make sure `data.txt` is in the same folder as the program.
* Add `data.txt` to `.gitignore` if you don’t want to upload user data.

---

## 🔮 Future Improvements

* 🏆 Leaderboard system
* 🎮 Difficulty levels
* 📈 Graphical performance stats
* 🌐 GUI version

---

## 👨‍💻 Author

Nirmithaa
---


