## Question 3

3.An iconic audio is trapped inside a noisy, chaotic audio signal —
distorted, modulated, and begging to be freed. Your mission? Use your
signal-slinging skills to build a filter and cut through the interference.
Think of it as your digital web, catching only the message and letting the
noise fall. Suit up, fire up your code, and bring it back to life. Hint given in
the repo :)

## Answer

### Tools and Libraries Used
 Python
 NumPy — for math and FFT computations
 SciPy — for reading wav files and designing filters
 Matplotlib — for plotting graphs

 ### Stage 1
 
 What I found and did - Loaded the corrupted.wav and extracted the sample rate and data list of frequencies from it and plotted in time domain. It didn't look like normal audio. Then calculated FFT and found peak frequency at 7300Hz which was not normal because normal speech lives in between 0 to 4000Hz. I concluded that the frequency of the signal was shifted from 0-4000Hz to 7300Hz

 ### Stage 2

 
 

