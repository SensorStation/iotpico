#include <stdio.h>

#include "hardware/gpio.h"
#include "boards/pico_w.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/cyw43_arch.h"
#include "lwipopts.h"

const uint LED_PIN = CYW43_WL_GPIO_LED_PIN;

const char ssid[] = "BoZoNoNo";
const char pass[] = "543212345";

int main()
{
    bi_decl(bi_program_description("This is Rusty's IOT Pico."));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();
    printf("Initied\n");

    if (cyw43_arch_init_with_country(CYW43_COUNTRY_UK)) {
        printf("Failed to initialize wifi\n");
        return 1;
    }
    printf("Wifi has been initialized");
    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(ssid, pass, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("Failed to connect to wifi\n");
        return 1;
    }
    printf("Connected to wifi\n");


    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (1) {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);

        gpio_put(LED_PIN, 1);
        puts("Hello, world!");
        sleep_ms(1000);
    }
}
