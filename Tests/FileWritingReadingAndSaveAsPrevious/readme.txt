PrivateTools.seq contains the following tools which help perform some semi-automated tests
(PrivateForEach.seq is a utility sequence used by the tools). To use one of these tools,
add the tool to the tools menu that launches the specified sequence.

1) ValidationSequence - Helps validate file formats are being written and read correctly by
comparing the results of one format against another (usually comparing XML and Binary against
ini is what makes the most sense since ini has a different implementation than binary and xml).

2) BenchmarkSequence - Benchmarks the performance of reading and writing files in ini, binary
and xml formats.

3) TestSaveAsPrevious - Tests "Save as Previous" by saving files as previous back to the version
they were last written as and comparing the results against each other (using xml format). In
general the files should be identical if everything is working as expected, but there are some
exceptions due to oddities in our conversion code (some easily fixable, some not).
