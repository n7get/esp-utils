#include <stdlib.h>
#include <string.h>
#include "esp_log.h"

#include "mem_helpers.h"

void *log_malloc(const char *tag, char *msg, size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        ESP_LOGE(tag, "Failed to allocate %zu bytes for %s", size, msg);
    } else {
#ifdef CONFIG_ESP_UTILS_LOG_MEM_FUNCTIONS
        ESP_LOGI(tag, "%s: malloc %zu bytes at %p", msg, size, ptr);
#endif
    }
    return ptr;
}

void *log_calloc(const char *tag, char *msg, size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        ESP_LOGE(tag, "Failed to allocate %zu bytes for %s", num * size, msg);
    } else {
#ifdef CONFIG_ESP_UTILS_LOG_MEM_FUNCTIONS
        ESP_LOGI(tag, "%s: calloc %zu bytes at %p", msg, num * size, ptr);
#endif
    }
    return ptr;
}

void log_free(const char *tag, void *ptr) {
    if (ptr == NULL) {
        ESP_LOGW(tag, "Attempted to free NULL pointer");
        return;
    }

#ifdef CONFIG_ESP_UTILS_LOG_MEM_FUNCTIONS
    ESP_LOGI(tag, "free pointer %p", ptr);
#endif

    free(ptr);
}

void *log_strdup(const char *tag, char *msg, const char *s) {
    if (s == NULL) {
        ESP_LOGE(tag, "Attempted to strdup NULL string for %s", msg);
        return NULL;
    }

    char *ptr = strdup(s);
    if (ptr == NULL) {
        ESP_LOGE(tag, "Failed to duplicate string for %s", msg);
    } else {
#ifdef CONFIG_ESP_UTILS_LOG_MEM_FUNCTIONS
        ESP_LOGI(tag, "%s: strdup %zu bytes at %p", msg, strlen(s) + 1, ptr);
#endif
    }
    return ptr;
}
