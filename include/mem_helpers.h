#pragma once

#include <stddef.h>

/**
 * Log mallocs with a tag and message for easier debugging. Logs an error if allocation fails.
 * 
 * @param tag Logging tag to identify the source of the allocation
 * @param msg Description of what the allocation is for (e.g. "xyz buffer")
 * @param size Number of bytes to allocate
 * @return Pointer to allocated memory, or NULL if allocation failed
 */
void *log_malloc(const char *tag, char *msg, size_t size);

/**
 * Log callocs with a tag and message for easier debugging. Logs an error if allocation fails.
 * 
 * @param tag Logging tag to identify the source of the allocation
 * @param msg Description of what the allocation is for (e.g. "xyz buffer")
 * @param num Number of elements to allocate
 * @param size Size of each element in bytes
 * @return Pointer to allocated memory, or NULL if allocation failed
 */
void *log_calloc(const char *tag, char *msg, size_t num, size_t size);

/**
 * Log frees with a tag for easier debugging. Logs a warning if attempting to free a NULL pointer.
 * 
 * @param tag Logging tag to identify the source of the free
 * @param ptr Pointer to memory to free (can be NULL)
 */
void log_free(const char *tag, void *ptr);

/**
 * Log strdup with a tag and message for easier debugging. Logs an error if allocation fails.
 * 
 * @param tag Logging tag to identify the source of the allocation
 * @param msg Description of what the allocation is for (e.g. "xyz buffer")
 * @param s String to duplicate
 * @return Pointer to duplicated string, or NULL if allocation failed
 */
void *log_strdup(const char *tag, char *msg, const char *s);
