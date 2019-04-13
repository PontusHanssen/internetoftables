# Internet of Tables

Workshop @ Omegapoint for connecting adjustable desks to the internet

# Setup

## Installera
1. Installera Arduino IDE [https://www.arduino.cc/en/main/software](https://www.arduino.cc/en/main/software)
2. Installera C340 USB Serial driver [https://wiki.wemos.cc/downloads](https://wiki.wemos.cc/downloads)

## Arduino IDE

1. `File -> Preferences -> Settings` sätt [http://arduino.esp8266.com/stable/package_esp8266com_index.json](http://arduino.esp8266.com/stable/package_esp8266com_index.json) i fälter `Additional Board Manager URLs`
2. `Tools -> Board -> Board Manager` installera "esp8266"
3. `Tools -> Board -> LOLIN(WEMOS) D1 R2 & mini`
4. Koppla in esp8266 med USB
5. `Tools -> Port -> COMX` där X är en siffra

# Vanliga fel

## Skrivbordet slutar röra på sig och knapparna funkar inte längre
När man kopplar friskt kan det hända att skrivbordet tröttnar på en. Det är inget att få panik över.

1. Koppla bort din esp8266
2. Dra ut strömkabeln från bordet och koppla in den igen.
3. Håll inne båda knapparna (upp och ner).
4. Vänta tills skrivbordet har (långsamt) rört sig till bottenläget.

## Överhettningsskydd
Skrivborden har automatiskt överhettningsskydd, så kör inte upp-ner-upp-ner i en för snabb loop. Om skyddet slår i så får man vänta i några minuter och alternativt även göra en återställning/kalibrering, se punken ovan.

# Exempelkod

I mappen `examples` hittar du några exempelprogram som går att köra i arduino IDE.
