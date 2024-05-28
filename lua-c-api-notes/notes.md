# notes

three important dsa in lua the state, the virtual stack and the registry table

## Lua State

When new lua_state is created, new interpreter thread is created which is associated with registry table and a virtual stack.

- lu_state stores the virtual stack whenever a lua api c function is called?
- It glues everything together and is the main parameter for API calls?

## registry table

contains global data and functions. The global data is registered to be available to Lua code in a certain state.

## How the Lua C Api Works

In order to the use the c api, you need put the necessary/ required arguments on the virtual stack and then call the wanted function.

## other notes

- use lua_dostring instead of lua_pcall and luaL_loadstring
- use lua_dofile instead of lua_pcall and luaL_loadfile
- lua_call is not protected use lua_pcall
  - new panic functions can be handled with lua_atpanic
