#include <seqan/vcf_io.h>

using namespace seqan;

int main()
{
    // Open input file.
    VcfFileIn vcfIn("example.vcf");

    // Attach to standard output.
    VcfFileOut vcfOut(vcfIn);
    open(vcfOut, std::cout, Vcf());

    // Copy over header.
    VcfHeader header;
    readRecord(header, vcfIn);
    writeRecord(vcfOut, header);

    // Copy the file record by record.
    VcfRecord record;
    while (!atEnd(vcfIn))
    {
        readRecord(record, vcfIn);
        writeRecord(vcfOut, record);
    }
    
    return 0;
}
