# ESP-Utils

A collection of utility functions and data structures for ESP-IDF projects, including memory management helpers, circular buffers, and linked list implementations.

## Features

- **Memory Helpers**: Logging wrappers for memory allocation (`malloc`, `calloc`, `free`, `strdup`)
- **Circular Buffer**: Efficient buffer implementation with callback-based data refilling
- **Linked List**: Generic linked list data structure with dynamic sizing

## Components

### Memory Helpers (`mem_helpers.h`)

Provides logging-enhanced memory allocation functions for debugging memory usage:

- `log_malloc(tag, msg, size)` - Allocate memory with logging
- `log_calloc(tag, msg, num, size)` - Allocate and zero-initialize memory with logging
- `log_free(tag, ptr)` - Free memory with logging
- `log_strdup(tag, msg, s)` - Duplicate a string with logging

### Buffer (`buffer.h`)

A circular buffer implementation that supports callback-based data refilling:

- `buffer_create()` - Create a new buffer with a fill callback
- `buffer_get_byte()` - Read a single byte from the buffer
- `buffer_peek()` - View buffer data without removing it
- `buffer_skip()` - Skip bytes in the buffer
- `buffer_destroy()` - Free buffer resources

The buffer calls a user-provided callback function when it needs more data, making it suitable for streaming scenarios.

### Linked List (`linked_list.h`)

A generic linked list implementation for storing arbitrary data:

- `linked_list_create()` - Create a new linked list
- `linked_list_push()` - Add an item to the list
- `linked_list_pop()` - Remove and retrieve the first item
- `linked_list_peek()` - View the first item without removing it
- `linked_list_size()` - Get the number of items in the list
- `linked_list_clear()` - Remove all items from the list
- `linked_list_destroy()` - Free all list resources

## Usage

### Integration with ESP-IDF

Add to your project's `idf_component.yml`:

```yaml
dependencies:
  esp-utils:
    git: https://github.com/your-repo/esp-utils.git
```

### Example: Buffer Usage

```c
#include "buffer.h"

// Define a fill callback
int my_fill_callback(void *context, uint8_t *buf, size_t max_len) {
    // Read data from a source (file, network, etc.)
    // Return number of bytes read, 0 for EOF, -1 for error
    return my_read_source(buf, max_len);
}

// Create and use the buffer
buffer_t *buf = buffer_create(256, my_fill_callback, NULL);
if (buf) {
    uint8_t byte;
    while (buffer_get_byte(buf, &byte) == 1) {
        // Process byte
    }
    buffer_destroy(buf);
}
```

### Example: Linked List Usage

```c
#include "linked_list.h"

// Create a linked list
linked_list_t *list = linked_list_create();

// Add items
int *value1 = malloc(sizeof(int));
*value1 = 42;
linked_list_push(list, (void *)value1);

// Retrieve items
void *item = linked_list_pop(list);

// Cleanup
linked_list_destroy(list, free);
```

## Platform Support

This component supports the following ESP32 targets:
- ESP32
- ESP32-S2
- ESP32-S3
- ESP32-C3
- ESP32-C2
- ESP32-C6
- ESP32-H2

## Requirements

- ESP-IDF >= 5.0.0

## License

MIT License

## Author

Robert N Ambrose &lt;weblib@muttsoft.com&gt;
