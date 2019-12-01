# Arduino
Arduino的一些code

主要是上課學的(經費不夠自己玩)

以Arduino執行

用C編譯

## LED
紅黃綠輪流閃
應用:
delay()//延遲

digitalWrite(對應格,Low)//調整電壓

## nightLight
夜燈，光感應，暗時發亮，亮時關燈
應用:
analogRead(A0)//感光指數

## Gun Game
由光感應器做的射擊遊戲

由亮度代表準度

且有伺服馬達移動標靶

圖:https://imgur.com/iSz6zpP

應用:(伺服馬達)

Servo myservo; // 建立Servo物件，控制伺服馬達

myservo.write()馬達旋轉角度
