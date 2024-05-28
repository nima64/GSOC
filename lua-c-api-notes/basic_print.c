#include "include/lauxlib.h"
#include "include/lua.h"
#include "include/lualib.h"
/**
* three important dsa in lua the state, the virtual stack and the registry table

*/

int main(int argc, char **argv) {

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushinteger(L, 42);
  lua_setglobal(L, "answer");

  char *code = "print(answer)";

  if (luaL_dostring(L, code) == LUA_OK) {
    lua_pop(L, lua_gettop(L));
  }

  lua_close(L);
  return 0;
}
