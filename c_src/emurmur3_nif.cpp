#include <erl_nif.h>
#include "MurmurHash3.h"

extern "C" {

ERL_NIF_TERM hash_x86_32(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM hash_x86_128(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM hash_x64_128(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

} // extern "C"

static ErlNifFunc nif_funcs[] =
{
    {"hash_x86_32", 2, hash_x86_32},
    {"hash_x86_128", 2, hash_x86_128},
    {"hash_x64_128", 2, hash_x64_128}
};


ERL_NIF_TERM hash_x86_32(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    uint32_t h;
    uint32_t seed;

    if (argc != 2)
        return false;
    if (!enif_inspect_binary(env, argv[0], &bin))
        return enif_make_badarg(env);
    if (!enif_get_uint(env, argv[1], &seed))
        return enif_make_badarg(env);

    MurmurHash3_x86_32(bin.data, bin.size, seed, &h);

    return enif_make_uint(env, h);
}

ERL_NIF_TERM hash_x86_128(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    uint32_t h;
    uint32_t seed;

    if (argc != 2)
        return false;
    if (!enif_inspect_binary(env, argv[0], &bin))
        return enif_make_badarg(env);
    if (!enif_get_uint(env, argv[1], &seed))
        return enif_make_badarg(env);

    MurmurHash3_x86_128(bin.data, bin.size, seed, &h);

    return enif_make_uint(env, h);
}

ERL_NIF_TERM hash_x64_128(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    uint32_t h;
    uint32_t seed;

    if (argc != 2)
        return false;
    if (!enif_inspect_binary(env, argv[0], &bin))
        return enif_make_badarg(env);
    if (!enif_get_uint(env, argv[1], &seed))
        return enif_make_badarg(env);

    MurmurHash3_x64_128(bin.data, bin.size, seed, &h);

    return enif_make_uint(env, h);
}


ERL_NIF_INIT(emurmur3, nif_funcs, NULL, NULL, NULL, NULL);
