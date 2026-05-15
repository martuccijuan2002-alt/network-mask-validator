/*Proyecto: Un "Validador de Máscaras de Red".

Qué hace: El usuario ingresa una IP y un CIDR (ej: /24), y tu programa le dice si es una IP válida de host o si es la dirección de red o de broadcast.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validadorIp(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void validadorHost(unsigned int, unsigned int, unsigned int, unsigned int);

int main (){
    
    unsigned int o1 = 0, o2 = 0, o3 = 0, o4 = 0, mascara, ip = 0, ipRed, ipBroadcast, m = 0, cant = 0;
    unsigned long long hostDisponible = 0;
    char entrada[25];

    /*El usuario ingresa una IP y un CIDR (ej: /24)*/
    printf("Ingresar una IP y un CIDR (ej: /24): ");
    fgets(entrada, sizeof entrada, stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    sscanf(entrada, "%u.%u.%u.%u/%u", &o1, &o2, &o3, &o4, &m);

    /*Se valida que la ip ingresada sea valida*/
    int control = validadorIp(o1, o2, o3, o4, m);
    if(control == 1){
        return 0;
    }

    /*ocd*/
    ip = (o1 << 24) | (o2 << 16) | (o3 << 8) | o4;

   /*Calcula los hostDisponible, calcula el valor de la mascara en binario, se calcula calucla la ip de RED y de Broadcast*/
    hostDisponible = 1ULL << (32 - m);
    if(m == 0){
        mascara = 0;
    }else{
        mascara = 0xFFFFFFFF << (32 - m);
    }
    ipRed = ip & mascara;   
    ipBroadcast = ip | (~mascara);

    /*Se valida que la ip ingresada sea de host y se muestran los datos de forma ordenada*/
    printf("\n=============================\nNETWORK MASK VALIDATOR\n=============================\n\n");



    validadorHost(ip, ipRed, ipBroadcast, m);
    printf("IP ingresada: %s\n", entrada);
    printf("Mascara: %d.%d.%d.%d (/%d)\n", (mascara >> 24) & 0xFF, (mascara >> 16) & 0xFF, (mascara >> 8) & 0xFF, (mascara & 0xFF), m);
    printf("--------------------------------------\n");
    printf("IP de Red: %u.%u.%u.%u\n", (ipRed >> 24) & 0xFF, (ipRed >> 16) & 0xFF, (ipRed >> 8) & 0xFF, (ipRed & 0xFF));
    printf("Ip de Broadcast: %u.%u.%u.%u\n", (ipBroadcast >> 24) & 0xFF, (ipBroadcast >> 16) & 0xFF, (ipBroadcast >> 8) & 0xFF, (ipBroadcast & 0xFF));

    if(m == 31){
        printf("Primer Host: %u.%u.%u.%u\n", (ipRed >> 24) & 0xFF, (ipRed >> 16) & 0xFF, (ipRed >> 8) & 0xFF, (ipRed & 0xFF) + 1);
        printf("Ultimo Host: %u.%u.%u.%u\n", (ipBroadcast >> 24) & 0xFF, (ipBroadcast >> 16) & 0xFF, (ipBroadcast >> 8) & 0xFF, (ipBroadcast & 0xFF)- 1);
        printf("Host Disponibles: 2\n");
    }else if(m == 32){
        printf("Primer Host: N/A\n");
        printf("Ultimo Host: N/A\n");
        printf("Host Disponibles: 1\n");
    }else{
        printf("Primer Host: %u.%u.%u.%u\n", (ipRed >> 24) & 0xFF, (ipRed >> 16) & 0xFF, (ipRed >> 8) & 0xFF, (ipRed & 0xFF) + 1);
        printf("Ultimo Host: %u.%u.%u.%u\n", (ipBroadcast >> 24) & 0xFF, (ipBroadcast >> 16) & 0xFF, (ipBroadcast >> 8) & 0xFF, (ipBroadcast & 0xFF)- 1);
        printf("Host Disponibles: %llu\n", hostDisponible - 2);
    }
    printf("--------------------------------------\n");
    printf("Mascara en binario: ");
    for(int i = 31; i >= 0; i--){
        printf("%u", ((mascara >> i) & 0b1));
        cant++;
        if(i == 0){
            break; 
        }
        if(cant == 8){
            printf(".");
            cant = 0;
        }
    }
    printf("\n\n");

    return 0;
}

int validadorIp(unsigned int o1, unsigned int o2, unsigned int o3, unsigned int o4, unsigned int m){
    /*Una ip tiene 32 bits en 4 octetos de 8bits, por lo tanto como maximo por cada octeto hay 255 posibilidades y como minimo 0.
    Una mascara puede tomar valores de 0 a 32. Validamos que se cumplan todas estas condiciones*/
    
    int control = 0;

    if(o1 < 0 || o1 > 255){
        printf("La IP ingresada no es valida\n");
        control = 1;
    }else if(o2 < 0 || o2 > 255){
        printf("La IP ingresada no es valida\n");
        control = 1;  
    }else if(o3 < 0 || o3 > 255){
        printf("La IP ingresada no es valida\n");
        control = 1;
    }else if(o4 < 0 || o4 > 255){
        printf("La IP ingresada no es valida\n");
        control = 1;
    }else if(m < 0 || m > 32){
        printf("La mascara no es valida\n");
        control = 1;
    }

    return control;
}

void validadorHost(unsigned int ip, unsigned int ipRed, unsigned int ipBroadcast, unsigned int m){
    /*Comparamos la ip ingresada con la ip de red y de broadcast, si es distinta entonces validamos que es una ip de host*/

    if (m == 32) {
        printf("Tipo de ip: HOST (Mascara /32 fija).\n");
    } else if (ip == ipRed) {
        printf("Tipo de ip: RED\n");
    } else if (ip == ipBroadcast) {
        printf("Tipo de ip: BROADCAST\n");
    } else {
        printf("Tipo de ip: HOST\n");
    }

    return;

}