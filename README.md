# PIC18F4620_Simple_Login_project ## Main Idea Of Project
This project uses linked list data structure to handle the dealing with users so that it becomes easy to add, remove and store the data and level of each one. Each user has a username, password and a level of accessbility, depending on the level the user has a maximum number of leds which can turn on at same time. Using GPIO module of PIC18F4628 microcontroller is needed to show the output of each mode in the program on LCD and needed also to get inputs through a push button and keypad then depends on the inputs a specific led is turned on or a buzzer will gives an alarm for few seconds.
### How To Use The Device
After turning on the device, it will gives a welcome message and follows it with a loading screen.
- The device will takes you the ID and password of first user which will be an admin.
Automatically the device switch to the mode of leds controll. In this mode the current user can turn on and off the leds dependes on his level and maximum turned on leds.
- The user can switch to the mode which the users can sign in, register or remove ..etc using push button.
- Using keypad from 1 to 4 buttons the current user will be able to turn on leds 1, 2, 3, and 4.
## Modes Of Device
### Controll Mode
In this mode LCD shows the current user (currently signed in) and the max allowed led to turn on this is in first line. In second line it shows the number of turned on leds. 
### Users Mode
This mode has 5 options:
- **Option 1 ( Sign in )** : The user can sign in to his accout using the ID and password and the leds which he turned on in the last time his signed in will be on.
- **Optoin 2 ( Add user )** : Any one can add an account to the device. Enter ID then password, in next display the level is needed ( level 1 : admin, level 2: sub admin, level 3: normal user). Each level has max number of turned on leds. Only in case of the new user to be admin the confirm of admin is required through the sign in.
- **Option 3 ( Remove user )** : To remove user an admin should sign in after entering the ID and password of removed account.
- **Option 4 ( Show users )**: This option will show all the registered users, thier levels and the turned on leds of each account.
- **Option 5 (Forget pass )**: In case of someone forgot his pass he can ask for admin to confirm then he can change the password of his account.
