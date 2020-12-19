# temp2lcd
v1.0.8

Aplicación hecha en Gambas para enviar información de temperatura del CPU/GPU al Arduino.

La aplicación transmite las temperaturas del *CPU* y el *GPU* hacia el Arduino vía el puerto USB.
Para que funcione correctamente es necesario tener instalado **lm-sensors** y **nvidia-smi**.

> Por el momento la aplicación solo funciona con tarjetas NVIDIA. 

Para obtener la temperatura del CPU la aplicación utiliza un *script* que encontré en https://stackoverflow.com/questions/50686262/how-to-get-average-cpu-temperature-from-bash

Lo interesante del script es que devuelve un promedio de temperatura de todos los *cores* disponibles. Alteré levente el script para que solo devuelva el valor numérico y la unidad en grados celsius.

Respecto del sketch del Arduino, es bastante sencillo. Recibe la información enviada por la aplicación y la muestra en un *display LCD (16x2)*.

También hay un LED conectado al PIN 13 que enciende cuando se produce el evento **Serial.available();**

En el repositorio se encuentra el código fuente. paquetes de instalación para **debian** y el sketch de Arduino.

Más información en mi blog: https://thenerdyapprentice.blogspot.com/

Saludos!.
