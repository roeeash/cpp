#pragma once

#ifdef __cplusplus

extern "C"
{

#endif

    class MassTrie
    {

        MassTrie();

        ~MassTrie();

        // put function

        bool put(const char *key, int klen, const char *value, int vlen);

        // delete function

        bool del(const char *key, int klen);

        // probe function

        bool probe(const char *key, int klen);
    };

#ifdef __cplusplus
}

#endif