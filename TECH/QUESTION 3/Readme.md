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
 
 What I found and did is first I loaded the corrupted.wav and extracted the sample rate and data list of frequencies from it and plotted in time domain. It didn't look like normal audio. Then calculated FFT and found peak frequency at 7300Hz which was not normal because normal speech lives in between 0 to 4000Hz. I concluded that the frequency of the signal was shifted from 0-4000Hz to 7300Hz

 ### Stage 2

 I found that the energy was sitting at 7300Hz instead 0-4000Hz. That means signal was AM modulated with frequency 7300Hz. The technique I used was multipling the signal by cos(2π × 7300 × t)  to bring it back to between 0-4000Hz because it was AM modulated so it was being multipled by cosien function with this argument containing 7300Hz frequency so multipllying it again can bring it back to 0-4000Hz but can shift it also upto 7300*2 = 14600Hz. so we need to filter it and reject all frequencies above 4000Hz. so we defined a low pass filter functionn and used the functions like butter nad filtfilt imported from the scipy.

 ### Stage 3

 I saw that after demodulation FFT graph showed 3 narrow spikes approximately at 1200Hz, 2200Hz, 4100Hz. These spikes do not belong to natural audio because natural audio is smooth, sharp spikes means something is done to this sound. So I used notch filter this filter does not filter frequency above or below it is precise and clears which frequency we want to clear so it removed the spikes.

 ### Stage 4
 After stage 3 audio was sounding pretty good but still had a constant offset DC component at 0Hz. This was a byproduct of the AM demodulation process. Technnique used was simple, substracted the mean of the signal and normalized the  amplitude scale betweem -1 to 1. why? Because the mean value represnts the constant DC offset substracting it so that it centers the wave back at zero.

 ### Final Output
 recorded.wav
 ### What was done to the signal
 1. It was AM modulated to 7300Hz.
 2. Three narrow bad noise tones injected.
 3. DC offset.

 
 

