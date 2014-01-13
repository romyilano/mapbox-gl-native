#ifndef LLMR_MAP_TILE
#define LLMR_MAP_TILE

#include "../geometry/linevertexbuffer.hpp"

#include <stdint.h>
#include <vector>
#include <llmr/util/vec2.hpp>

namespace llmr {

class tile {
public:
    tile(int32_t z, int32_t x, int32_t y);

    void setData(uint8_t *data, uint32_t bytes);
    bool parse();
    void parseLayer(const uint8_t *data, uint32_t bytes);
    void parseFeature(const uint8_t *data, uint32_t bytes);
    void loadGeometry(const uint8_t *data, uint32_t bytes);

    void cancel();

    static uint64_t toID(int32_t z, int32_t x, int32_t y, int32_t w = 0);
    static vec4<int32_t> fromID(uint64_t id);

public:
    const int32_t z, x, y;
    bool loaded;
    bool cancelled;
    linevertexbuffer lineVertex;

private:
    // Source data
    uint8_t *data;
    uint32_t bytes;

};

}

#endif
