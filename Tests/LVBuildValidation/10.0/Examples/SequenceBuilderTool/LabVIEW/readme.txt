** README.TXT **

This example program acts as a tool for creating and executing new test sequences based upon existing test sequences.  This tool clones prewritten and configured test steps located in a template sequence to create and/or execute a new test sequence.  

For example, the template sequence file might contain a list of all the steps needed to test products within a particular product line.  This tool enables you to build sequences for each product in the product line by selecting which steps in the template sequence you want to use to test each product.  Once the steps in the template sequence are selected for that product, they are cloned and inserted into a new sequence file that can then be executed and/or saved to disk.


To Demo:

Open the Sequence Builder.seq sequence file using the TestStand Sequence Editor.  Select "Run MainSequence" from the Execute menu in the Sequence Editor.  When prompted, select which template sequence file to use.  For this example, select "Template Sequence.seq" as the template sequence file.  Next, choose whether you want to manually select which template steps to use or if you want the tool to read which steps to use from an *.ini file.  If you select the *.ini option then select "Build Sequence.ini" when prompted. Finally, select which execute and/or Save option you wish to use.  If you chose to execute the new sequence, it will be executed using the Test UUT entry point.


Note:

*This example can also be added to the Tools menu for easier access and usability.  

*You must have the TestStand Development license on any computer that uses this tool since it is creating sequence files.

*You should avoid having steps with the same name in your template sequence file.