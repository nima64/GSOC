#include "include/lauxlib.h"
#include "include/lua.h"
#include "include/lualib.h"

// must follow protocol of lua_CFunction https://www.lua.org/pil/26.1.html
// typedef int (*lua_CFunction) (lua_State *L);
// when we call the function it pops arguments off the stack,
// we also have to type check them.
int multiplication(lua_State *L) {

  // check arg 1 is int
  int a = luaL_checkinteger(L, 1);

  int b = luaL_checkinteger(L, 2);

  lua_Integer c = a * b;

  // pushing on stack to be returned
  lua_pushinteger(L, c);

  return 1; // The number of returned values
}

int main(int argc, char **argv) {

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushcfunction(L, multiplication);

  lua_setglobal(L, "mul");

  char *code = "print(mul(3,4))";

  if (luaL_dostring(L, code) == LUA_OK) {
    lua_pop(L, lua_gettop(L));
  }

  lua_close(L);
  return 0;
}
