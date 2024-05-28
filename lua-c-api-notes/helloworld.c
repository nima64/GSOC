#include "include/lauxlib.h"
#include "include/lua.h"
#include "include/lualib.h"
/**
* three important dsa in lua the state, the virtual stack and the registry table

*/

int main(int argc, char **argv) {

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  // Our Lua code, it simply prints a Hello, World message
  char *code = "print('Hello, World')";

  // Here we load the string and use lua_pcall for run the code
  if (luaL_loadstring(L, code) == LUA_OK) {
    if (lua_pcall(L, 0, 0, 0) == LUA_OK) {
      // If it was executed successfuly we
      // remove the code from the stack
      lua_pop(L, lua_gettop(L));
    }
  }

  lua_close(L);
  return 0;
}
