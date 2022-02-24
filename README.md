# Multiuser-water-well-automation
Water wells can be multi or single user. If its multiuser well, there can be some error in usage calculations which is made by hand and there can be some unexpected users or usages because there is no key or anything about safety. So, ı made this project for a request from a farmer costumer. 

I used Rep Rams 1.4 Compatible LCD Display Kit that consist a 20x4 display to show menu for users to view full time usages or to calculate bill for each user, a rotary encoder to enable movement on the menu, a SD card socket to write or read data from a sd card and a buton for emergancy. Also, ı used DS1302 RTC module to get real time. I made a circuit to avoid errors when the power is cut off. Also, ı used EEPROM module that integrated on arduino mega board to fast store datas about user usages when the power gone. I used 2 channel relay to open or close 3-phase asynchronous motor. Lastly, there is RC522 13.56 Mhz RFID reader to read chips that are distributed to users.

I shared pictures of each component ı used. Also, ı added libraries ı used for this project.

If you want to know how 2 small relays start and turn off a 3 phase motor, ı shared connections to contactor.
