-module(emurmur3).
-export([init/0,hash_x86_32/2,hash_x86_128/2,hash_x64_128/2]).

init() ->
    NifName = "emurmur3_nif",
    NifFileName = case code:priv_dir(emurmur3) of
        {error, bad_name} -> filename:join("priv", NifName);
        Dir -> filename:join(Dir, NifName)
    end,
    case erlang:load_nif(NifFileName, []) of
        ok ->
            ok;
        {error,{upgrade,_}} ->
            ok;
        {error,{reload,_}} ->
            ok
    end.


hash_x86_32(_Key,_Seed) ->
	erlang:nif_error(not_loaded).

hash_x86_128(_Key,_Seed) ->
	erlang:nif_error(not_loaded).

hash_x64_128(_Key,_Seed) ->
	erlang:nif_error(not_loaded).

