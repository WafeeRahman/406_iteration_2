#include <stdlib.h>
#include "aalloc.h"

Arena create_arena(size_t size)
{
  Arena arena = {0};
  arena.memory = malloc(size);
  arena.size = size;
  return arena;
}

void *aalloc(Arena *arena, size_t size)
{
  if(arena->size >= arena->offset + size)
  {
    char *block = arena->memory + arena->offset;
    arena->offset += size;
    return block;
  }
  
  return NULL;
}

void afree(Arena *arena, size_t size)
{
  if(arena->offset - size >= 0)
  {
    arena->offset -= size;
  }
}

void aclear(Arena *arena)
{
  arena->offset = 0;
}

void destroy_arena(Arena arena)
{
  free(arena.memory);
}