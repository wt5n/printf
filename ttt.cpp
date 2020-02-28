float64 C_IOHandler::readFloat80(IColl<uint8> buffer, uint32 *ref_offset)
{
    uint32 &offset = *ref_offset;

    //80 bit floating point value according to the IEEE-754 specification and the Standard Apple Numeric Environment specification:
    //1 bit sign, 15 bit exponent, 1 bit normalization indication, 63 bit mantissa

    float64 sign;
    if ((buffer[offset] & 0x80) == 0x00)
        sign = 1;
    else
        sign = -1;
    uint32 exponent = (((uint32)buffer[offset] & 0x7F) << 8) | (uint32)buffer[offset + 1];
    uint64 mantissa = readUInt64BE(buffer, offset + 2);

    //If the highest bit of the mantissa is set, then this is a normalized number.
    float64 normalizeCorrection;
    if ((mantissa & 0x8000000000000000) != 0x00)
        normalizeCorrection = 1;
    else
        normalizeCorrection = 0;
    mantissa &= 0x7FFFFFFFFFFFFFFF;

    offset += 10;

    //value = (-1) ^ s * (normalizeCorrection + m / 2 ^ 63) * 2 ^ (e - 16383)
    return (sign * (normalizeCorrection + (float64)mantissa / ((uint64)1 << 63)) * g_Math->toPower(2, (int32)exponent - 16383));
}