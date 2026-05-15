# Network Mask Validator - IPv4 Subnetting Tool

![C Badge](https://img.shields.io/badge/Language-C-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

##  Descripción
Esta herramienta es una aplicación de consola desarrollada en **C** que permite validar direcciones IPv4 y calcular automáticamente los parámetros de una subred. El objetivo del proyecto es proporcionar una utilidad rápida para profesionales de redes que necesiten verificar si una dirección IP específica es un Host, una dirección de Red o de Broadcast dentro de un esquema de direccionamiento CIDR.

---

##  Funcionalidades Principales

* **Análisis de Direccionamiento:** Calcula la dirección de red, la dirección de broadcast y el rango de hosts utilizables (primer y último host).
* **Identificación de Tipo:** Determina si la IP ingresada es una dirección de Red, Broadcast o un Host válido.
* **Validación de Errores:** Verifica que los cuatro octetos de la IP estén en el rango de 0-255 y que la máscara CIDR sea válida (0-32).
* **Cálculo de Disponibilidad:** Informa la cantidad total de hosts disponibles en la subred ingresada, con manejo especial para máscaras /31 y /32.
* **Representación Binaria:** Muestra la máscara de red en formato binario para facilitar la comprensión visual de la segmentación.

---

##  Lógica Técnica y Habilidades Demostradas
El proyecto demuestra un dominio sólido de la arquitectura de redes y lógica de programación a bajo nivel:

* **Manipulación de Bits (Bitwise):** Implementación de operadores lógicos (`<<`, `&`, `|`, `~`) para el cálculo preciso de máscaras y segmentos de red.
* **Procesamiento de Datos:** Uso de funciones de la librería estándar de C como `sscanf` y `fgets` para realizar el parsing de la entrada del usuario de manera estructurada.
* **Conocimiento de Protocolos:** Aplicación de los conceptos de direccionamiento IPv4 y subneteo aprendidos en la formación técnica y de ingeniería.

---

##  Instrucciones de Uso

Para compilar y ejecutar la herramienta en cualquier entorno con un compilador de C (como **GCC**):

### 1. Compilación
```bash
gcc Validador.c -o validador
```

### 2. Ejecución
```bash
./validador
```

### 3. Ejemplo de Entrada
Al iniciar el programa, ingresa la dirección en formato IP/CIDR:
```text
192.168.10.15/24
```

---

##  Ejemplo de Salida (Output de la Consola)
```text
=============================
NETWORK MASK VALIDATOR
=============================

Tipo de ip: HOST
IP ingresada: 192.168.10.15/24
Mascara: 255.255.255.0 (/24)
--------------------------------------
IP de Red: 192.168.10.0
Ip de Broadcast: 192.168.10.255
Primer Host: 192.168.10.1
Ultimo Host: 192.168.10.254
Host Disponibles: 254
--------------------------------------
Mascara en binario: 11111111.11111111.11111111.00000000
```