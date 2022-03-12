# Multiuser-water-well-automation
Water wells can be multi or single user. If its multiuser well, there can be some error in usage calculations which is made by hand and there can be some unexpected users or usages because there is no key or anything about safety. So, ı made this project for a request from a farmer. At the end ı sold it to him.

I used Rep Rams 1.4 Compatible LCD Display Kit that consist a 20x4 display to show menu for users to view full time usages or to calculate bill for each user, a rotary encoder to enable movement on the menu, a SD card socket to write or read data from a sd card and a buton for emergancy. Also, ı used DS1302 RTC module to get real time. I made a circuit to avoid errors when the power is cut off. Also, ı used EEPROM module that integrated on arduino mega board to fast store datas about user usages when the power gone. I used 2 channel relay to open or close 3-phase asynchronous motor. Lastly, there is RC522 13.56 Mhz RFID reader to read chips that are distributed to users.

I shared pictures of each component ı used. Also, ı added libraries ı used for this project.

about 2 small relays turn on and off a 3 phase motor, connections to contactor.
![image](https://user-images.githubusercontent.com/55800601/158028261-3b1138ab-82d9-4f13-a68b-7420d40ecaab.png)
power cutoff circuit with reverse current protection
![image](https://user-images.githubusercontent.com/55800601/158028317-3a94d404-1178-4e8e-9655-d85ed1e7a996.png)
rep ramps 20x4 lcd kit
![image](https://user-images.githubusercontent.com/55800601/158028350-d3aaef1c-eea1-449c-8ea8-2e4a98bab759.png)
rep ramps 1.4 lcd kit connections to arduino mega pins
![image](https://user-images.githubusercontent.com/55800601/158028331-9bb5815a-8b16-4982-a655-4ea780c8ba47.png)
relay kit and connections
![image](https://user-images.githubusercontent.com/55800601/158028370-12e6bc54-6851-4e5a-9ee3-58ebc5c5895b.png)
rfid module and connections
![image](https://user-images.githubusercontent.com/55800601/158028392-d7315efa-8bb5-4f03-b48a-4039a9a95af4.png)
rtc kit and connections
![image](https://user-images.githubusercontent.com/55800601/158028405-38360271-6cb2-4ca1-8765-bc7baf1c9b0a.png)
arduino mega ports
![image](https://user-images.githubusercontent.com/55800601/158028431-413057a9-87b6-4a5c-a302-79aee6553f2c.png)





