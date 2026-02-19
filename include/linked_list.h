#pragma once

#include <stddef.h>
#include "esp_err.h"

// Node structure for the linked list
typedef struct linked_list_node {
    void *data;
    struct linked_list_node *next;
} linked_list_node_t;

// Linked list structure
typedef struct linked_list {
    linked_list_node_t *head;
    linked_list_node_t *tail;
    size_t size;
} linked_list_t;

// Function pointer type for freeing node data
typedef void (*linked_list_free_fn)(void *data);

// Create a new linked list
linked_list_t *linked_list_create(void);

/**
 * Clear the linked list without destroying it
 * @param list The linked list to clear
 * @param free_fn Function to free the data of each node
 */
void linked_list_clear(linked_list_t *list, linked_list_free_fn free_fn);

/**
 * Destroy the linked list and free all nodes
 * @param list The linked list to destroy
 * @param free_fn Function to free the data of each node
 */
void linked_list_destroy(linked_list_t *list, linked_list_free_fn free_fn);

/**
 * Peek at the first item in the list without removing it
 * @param list The linked list to peek at
 * @return Pointer to the data of the first item, or NULL if the list is empty
 */
void *linked_list_peek(linked_list_t *list);

/**
 * Get the next node in the list
 * @param node The current node
 * @return The next node in the list or NULL if at the end
 */
linked_list_node_t *linked_list_next(const linked_list_node_t *node);

/**
 * Pop the first item from the list
 * @param list The linked list to pop from
 * @return Pointer to the data of the first item, or NULL if the list is empty
 */
void *linked_list_pop(linked_list_t *list);

/**
 * Shift an item to the front of the list
 * @param list The linked list to modify
 * @param data Pointer to the data to add to the front
 */
void linked_list_shift(linked_list_t *list, void *data);

/**
 * Add an item to the end of the list
 * @param list The linked list to modify
 * @param data Pointer to the data to add to the end
 */
void linked_list_push(linked_list_t *list, void *data);

/**
 * Remove the first node with matching data pointer (shallow compare)
 * @param list The linked list to modify
 * @param data Pointer to the data to remove
 * @return ESP_OK if a node was removed, ESP_FAIL otherwise
 */
esp_err_t linked_list_remove(linked_list_t *list, void *data);

/**
 * Get the size of the list
 * @param list The linked list to query
 * @return The number of elements in the list
 */
size_t linked_list_size(const linked_list_t *list);

/**
 * Iterate over the list
 * @param list The linked list to iterate
 * @return The first node in the list
 */
linked_list_node_t *linked_list_begin(const linked_list_t *list);

/**
 * Get the next node in the list
 * @param node The current node
 * @return The next node in the list
 */
linked_list_node_t *linked_list_next(const linked_list_node_t *node);

/**
 * Sort the linked list using a comparison function
 * @param list The linked list to sort
 * @param node_order_compare Comparison function to determine node order
 */
void linked_list_sort(linked_list_t *list, int (*node_order_compare)(const void *a, const void *b));
