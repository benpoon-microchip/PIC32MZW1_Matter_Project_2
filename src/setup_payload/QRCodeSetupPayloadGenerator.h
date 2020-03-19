/*
 *
 *    <COPYRIGHT>
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file describes a QRCode Setup Payload generator based on the
 *      CHIP specification.
 *
 *      The encoding of the binary data to a base45 string is as follows:
 *      - Every 2 bytes (16 bits) of binary source data are encoded to 3
 *        characters of the Base-45 alphabet.
 *      - If an odd number of bytes are to be encoded, the remaining
 *        single byte is encoded to 2 characters of the Base-45 alphabet.
 */

#include "SetupPayload.h"

#include <bitset>
#include <string>
using namespace std;

#ifndef _QR_CODE_SETUP_PAYLOAD_GENERATOR_
#define _QR_CODE_SETUP_PAYLOAD_GENERATOR_

namespace chip {

class QRCodeSetupPayloadGenerator
{
private:
    bitset<kTotalPayloadDataSizeInBits> mPayloadBits;
    SetupPayload mPayload;
    // points to the current index within the bitset
    int mPayloadBitsIndex;

    void populateInteger(uint64_t input, size_t numberOfBits);
    void populateVersion();
    void populateVendorID();
    void populateProductID();
    void populateCustomFlowRequiredField();
    void populateRendezvousInfo();
    void populateDiscriminator();
    void populateSetupPIN();
    void populateReservedField();
    void resetBitSet();
    void generateBitSet();

public:
    string payloadBinaryRepresentation();
    string payloadBase45Representation();
    QRCodeSetupPayloadGenerator(SetupPayload setupPayload) : mPayload(setupPayload){};
};

}; // namespace chip

#endif /* _QR_CODE_SETUP_PAYLOAD_GENERATOR_ */
