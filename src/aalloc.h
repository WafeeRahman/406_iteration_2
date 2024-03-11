#ifndef AALLOC_INCLUDE_H
#define AALLOC_INCLUDE_H

typedef struct Arena
{
  char *memory;
  size_t size;
  size_t offset;
} Arena;

#endif

Arena create_arena(size_t size);
void *aalloc(Arena *arena, size_t size);
void afree(Arena *arena, size_t size);
void aclear(Arena *arena);
void destroy_arena(Arena arena);