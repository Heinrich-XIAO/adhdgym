---
title: "adhdgym"
author: "@itsme Heinrich Xiao"
description: "Gamifies your gym."
created_at: "2025-06-11"
---

# adhdgym

Total time (not including build time): 14hr 37mins

Total Design time: 9hr 37mins

Total Coding time: 5hr

## June 11, 2025
Chose ESP32-C3 Seeed XIAO for MCU since I use XIAO for everything. DHT11 for temp and humidity info to estimate the speed of sound for the ultrasonic distance sensor.

The PCB was made as small as possible because why make a PCB bigger than it should be. 
![1749687646-wayshot](https://github.com/user-attachments/assets/26ef98c3-e903-4cc1-9a6c-fc85e012ccc1)
![1749687704-wayshot](https://github.com/user-attachments/assets/9f4e885c-7c24-450c-8668-cdd658201e33)

16:30-18:15 Time spent: 1hr 45mins


## June 13, 2025
Time spent: 4hr 22mins

First, I designed the case for the PCB. Just the PCB.

![1749866180-wayshot](https://github.com/user-attachments/assets/7dde1459-129e-4f79-90d6-b6c6b528875f)

Then, I decided I should work on the case for the ultrasonic sensor. I took inspiration from [this]https://grabcad.com/library/simple-cover-for-hcsr04-sensor-1(https://grabcad.com/library/simple-cover-for-hcsr04-sensor-1), and started designing my case for the ultrasonic sensor.

![1749866450-wayshot](https://github.com/user-attachments/assets/69e325e2-a7dc-466f-92b8-0965452b1cb5)

Finally, the logical thing to do was to add everything together, and make the final assembly. This was also the first time I made an exploded view.

![1749866539-wayshot](https://github.com/user-attachments/assets/1b22119a-2a0d-48eb-b218-9df7db15cf8b)

## June 14, 2025
Time spent: 3hr

I was only able to use my phone to do this, so I had to learn how to use onshape on mobile. I didn\'t do much, but i fixed some of the formatting of the parts so i could export them. this was mostly just grouping parts that should be grouped together, but it was also an opportunity to learn how to actually use onshape mobile ideally, not waste dozens of minutes on trying every button until one of them did what i wanted them to. after this, i just exported everything and sent it to my computer (once i was able to use it). on my computer, i just committed everything normally, and didn't waste that much time.
 
Time spent: 30mins

I added the screenshots for PCB, Schematics and CAD to the README.md, and also added a BOM.

Time spent: 2hr

Writing firmware is hard. Especially when you don't have the microcontroller or even something similar to the one you're using. 

## June 15, 2025
Time spent: 3hr

Writing code is hard. Especially when you decided to use vanilla html, js and css. i chose to use [vanilla js](http://vanilla-js.com/) because its very light weight and adds a whole zero bytes to my build size (im not even buliding anything) I decided to use the vanilla canvas api. note to self: dont use the vanilla canvas api next time.
![1749993224-wayshot](https://github.com/user-attachments/assets/20c145d9-2074-4586-83fd-db35d9613086)
