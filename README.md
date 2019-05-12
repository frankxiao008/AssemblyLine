# Project – Assembly Line - Inventory Items and Project Utilities



In this project, you are to code a simulation of an assembly line in three separate milestones.



Upon successful completion of this project, you will have demonstrated the abilities to

- design and code a composition
- work with vector and queue containers from the Standard Template Library
- work with class variables and functions
- parse a string into tokens
- report and handle exceptions
- move objects from one container to another



**PROJECT OVERVIEW**

The project simulates an assembly line that fills customer orders from inventory. Each customer order consists of a list of items that need to be filled. The line consists of a set of stations. Each station holds an inventory of items for filling customer orders and a queue of orders to be filled. Each station fills the next order in the queue if that order requests its item and that item is still in stock. A line manager moves the customer orders from station to station until all orders have been processed. Any station that has used all of the items in stock cannot fill any more orders. Orders become incomplete due to a lack of inventory at one or more stations. At the end of all processing, the line manager lists the completed orders and the orders that are incomplete. The figure below illustrates the classes that constitute the simulator and the process of filling orders as they move along the pipeline.



**SPECIFICATIONS**

Milestone 1 builds the Inventory and the Utilities for the Assembly Line. This milestone consists of four modules:

- **project** (supplied)
- **AssemblyLine** (supplied)
- **Utilities**
- **ItemSet**

Enclose all your source code within the **sict namespace** and include the necessary guards in each header file. The output from your executable running Visual Studio with the following command line argument should look like

**Command Line : C:\Users\...\Debug\MS1.exe**  **Inventory.txt**

**Inventory Assembly**

**==================**

**Items in Stock**

**--------------**

**CPU          [123456] Quantity 5   Description: Central Processing Unit**

**Memory       [654321] Quantity 10  Description: Basic Flash Memory**

**GPU          [456789] Quantity 2   Description: General Processing Unit**

**SSD          [987654] Quantity 5   Description: Solid State Drive**

**Power Supply [147852] Quantity 20  Description: Basic AC Power Supply**

**For Manual Validation**

** getName(): CPU**

** getSerialNumber(): 123456**

** getQuantity(): 5**

** getSerialNumber(): 123457**

** getQuantity(): 4**

**Inventory Assembly Complete**

The input for testing your solution is stored in a supplied file. The name of the file is specified on the command line as shown in red above. Its records are

**CPU|123456|5|Central Processing Unit**

**Memory|654321|10|Basic Flash Memory**

**GPU|456789|2|General Processing Unit**

**SSD|987654|5|Solid State Drive**

**Power Supply|147852|20|Basic AC Power Supply**

Each record consists of 4 fields delimited by a prescribed char (&#39; **|**&#39;) for the project. The fields are:

- Name of the inventory item in the item set
- Serial number to be assigned to the item extracted from the set
- Number of items in the item set
- Description of  any item in the item set

Utilities Module

The Utilities module is a support module that contains the functionality that is common across the system. All objects in the system parse string data in the same way, use the same delimiter and report data fields in tabular format.

Design and code a class named  **Utilities**  for extracting tokens from a string, which consists of a set of fields separated by a specified delimiter and determining a field width that is sufficiently large to accommodate the tokens for a specified field. The field width is to be used to construct the output tables for the project (as shown in the sample output above). Tokens in a string are separated by one delimiter character (see the input file shown in red above).

Your class design includes the following public member functions:

- A default constructor that places the object in a safe empty state and initializes its field width to a size that is less than the possible size of any token.
-


**const**  **std::**** string **** extractToken( ****const**  **std::**** string ****&amp; str,**  **size\_t**** &amp; next\_pos) **– a modifier that receives a reference to an unmodifiable string** str **and a reference to a position** next\_pos **in that string. This function extracts the next token in the string starting at the position** next\_pos **, and ending immediately before the delimiter character. This function compares the size of the extracted token to the field width currently stored in the object and if the size of the token is greater than that width increases that width. This function returns in** next\_pos** the position of the next token in the string if one exists. If not, this function returns the position that is beyond the end of the string. This function reports an exception if one delimiter follows another  without any token between them.


**const**  **std::**** string **** extractToken( ****const**  **std::**** string ****&amp; str,**  **size\_t**** &amp; next\_pos) **– a modifier that receives a reference to an unmodifiable string** str **and a reference to a position** next\_pos **in that string. This function extracts the next token in the string starting at the position** next\_pos **, and ending immediately before the delimiter character. This function compares the size of the extracted token to the field width currently stored in the object and if the size of the token is greater than that width increases that width. This function returns in** next\_pos** the position of the next token in the string if one exists. If not, this function returns the position that is beyond the end of the string. This function reports an exception if one delimiter follows another  without any token between them.
- **const**** char **** getDelimiter() **** const**– a query that returns the delimiter character
- **size\_t** **getFieldWidth()**  **const** – a query that returns the field width for the current object
- **void** **setDelimiter(const char d)** – a modifier that set the delimiter character for all object of this class
- **void** **setFieldWidth(size\_t)** – a modifier that set the field width for the current object

ItemSet Module

Design and code a class named  **ItemSet**  for managing the stock inventory of a particular item. Your class design includes the following public member functions:

-
??
 ![](data:image/*;base64,iVBORw0KGgoAAAANSUhEUgAAAMwAAAEuCAIAAABNu2qYAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAAEnQAABJ0Ad5mH3gAABvtSURBVHhe7Z3rkxXVtcDnf8pXSywhZapSlS8mlUrUsirBwXxgEOVeMYX3RhGJD0LCw4iOSUmRiBK4eYBaYiLXK5YE8BqZEbjDS5iB4T3vJ8hde6+1u9fa3X0ePb1nus9Zv1oxZ797Zv/Yu89jn+m4oyiBUcmU4KhkSnBUMiU4KpkSHJVMCY5KpgRHJVOCo5IpwVHJlOCoZEpwVDIlOHOS7Pr1awcO7N/26q+3bn5p7TOrV65YqtFKAXMKMwvx4f53Lw9eollvnpyS9fefB7fgIv68Z+fxr4719Z24cvXa+ORsgzGBMXWr8Zj0YrpWTDUSM1HcxphuJGYpZpqJ2ShuZcU3qXErGbfT43Yj8Q1FNnd43Lx5A2YWYu/fdq9/fs3LLz4Dj8mAZsgj2fvv/QXGA7dGx2cHrkycODf81ZmhKI5DnDVx4uwwxbnhkzy+Hv4/jPMjGH0QF+I4BdFPcbp/1MTA6BkWZyEuUpy7OGbi0tjXLM5DDFJcGBzH6L8sYuBKFBMYF6/GcelaHIPXJ6O4fIPiCsRNiqs3pyiGpq65uA4xTHFjeJpiZPomi6HRKGYwhsdEjECMm4BfNcXE7BiLcQj6d3uLQv5r5P+uon8q/r8B6XpS32/ugHPfwMoCq9r2N1+bnZkhFRqjOckmJsZhAQPJ4IK+vjTee3rIBDNMJWtJyaL1Dxz4/OihX298HkxAJRqhOclA5C+//Bx+O+AQGaaStY1k1jOzjcKSBp41vp41IRlszHADCL+antM3IVSytpUMgPXsd2+8Yr2oT6OSgbxwHwbXAfaoZG0uGXr2u+6t77+/9+rVq1aQWjQqGWyU8MwCphMNU8laT7KZmdmJiYlJaNOYZFcuD65ft6a3p+fMmTPWkUwakuzy4CV4Bgs/87FTZJhK1mqSzd4Cw0ZHR8fGxianhGdZkgHwLHD/B++dOHGir6+PstJoSDJ4OglxfnBcJWtJyWANGx8fP3fu3Nq1a7dt2zYyMjI1Pd2IZIcOHXzt1U0gGXD69GnKTdCQZCDs8a+O9ZweUslaT7JpZ9jq1avvu++++++/HzwbGhqaggb1JBsYuLz22dUoGTAwMEAFkoYkg1v+S5cGwLCakh1be3cHcNf6Y0El++OjZpSIRRu+UsnmINktNOypp576/ve//5vf/ObZZ5/9wQ9+8Nprr924cQM9qyHZ9ZtjTz25nBSzUIGkIcl+vrpramqyack+2XwXpO/e/PfCJOtdf48ZglNHsiNbF0Gle175TCVLkYwMgzUMDHvzzTcHBwePHz/+3HPP/fCHP3z99devXbtmngfcAs3SJYMfZ+WKpeSX5cKFC1TGaEgy6Aj+26xkf//lYpMuULJdXabDjo5Hdrnt8p9bOmtK9umvlpgGKllCMtgl4U6fG9bb27tmzRpYzHp6esCzH//4x93d3VevXrXrGXlWV7KTJ09SGSOUZG8+Yh5H3PVCDxq2vZNygJ++jZLtW2qTS9/pXWeWHWDJ85+NnHqHlOpYtOXjLMnYPdnbP8NCw7LdxjCeAyzaeFwliyTD55IgE9yEoWGrVq363ve+B2sYePbFF1+sW7fu4Ycf3rVrF9ScnplpUDKAyhjzKhk3DLGekWQ1uPvlXrtdvst67XqLSbZT+gQs26OS1ZIM9sGxsbE33nhj+/btaNgDDzwAyQ0bNvzoRz/atGnT0aNHIfnBBx+AZDPllCxluzxob9E6Fq87aPbKAy/Y0mX7YsmW7YO98sBLdoMzCxtsl73rcW179F0r2eiZQ1vsII57thwEyf5pb7w6lrxw2OyVBzfYHn72nm6XNSTDxQzuycCwJ5544sEHH9y9ezfk9Pf3b9y4EYTbvHkzPDbLGDRo+J4MoDLGPEq2021/nEVbDsTbpb0no12ya4e9J/sDPpeMJLNxlqv2s/fO/WkFPebcs/VTlazWPZm56wfDHn/8cVAKDJuExW1qGv4DN+/g2UMPPQSeweOm7skAKmPMn2T/wKWro2u7f+PfvGT2dbK3aDdc8QIuXR0r3tYb/4YlgyUK78nQMEhOTU+b9y5hJ52aOn/+PHi2dOnSUt+T1VjJ4P4MJTvwYte6T5uRbFcX3pwJye7ZetCtZIs2fIWSfbphxYtHVLKakk1Owj3Zzp079+zZA2sYiBW9QQ4PIAlPPKH0448/hsJZUK+ckp14K94f7Y1/j3vyGLGkWclsQmBfJ/vqBf/1syUo2fk98U6qN/5cMggwCVYpwBlGkt26DesZtDWlYFh0119Kyc4Ob3fPBlNfwrB3/U1tl/zZpeGRP6W/hIF3/RjvuHyVzJMMArZIuOVyhsWSoWdwy282yuxX/OdfMgp977JCkmGkShaFSqaSqWQqmUqmkqlkKplKppKpZCqZSqaSqWQqmUrmUMlUMpVMJWt3yfb+pKNru0qmktWmGclAqYiu7SqZSlawZH9c3tGx+Ln/cSvZJ5t/8sselUwlK1AykGnxWjAse7t0n1sEunY4yXYsoyz8+DVEnPPoPpVMJWOSwTJ296YPa92T9azr3PwPu5Lt6LQfXQTJ3u6yn8BmK9k7Jue/dSVTydIle2QvPGjoxh/c6txrJPt0y12wqnHJPttyt/swmUqmkjUvGT9LgpLhYmbo2uE8cycujWoqmUrGJKt7TwaGLaLtMl7JbJgbf7tLHkDJ8Mbf5nyskqlkTLKhD9fDfX3ms0tz19+5F7dLuCfzJftsy12eZLBvqmQqmSeZCfMqhuPuzX8X22V8kOSnnW4lo70SWLLuM7td0l4JmC8r0O1SJUtIlnJPpm8rqWQNoJKpZCqZSqaSqWQqWV1UMpVMJVPJVDKVTCWri0qmkqlkKplKppKpZHVRyVQylUwlU8lUMpWsLiqZSqaSqWQqmUqmktVFJVPJVDKVTCVTyVSyuqhkKplKppKpZCqZSlYXlUwlU8lUspaQ7Pbt233nhyBOXaA4fWGYon/4TFqc7R+hGBg5x+PiyNcYl0ZT4zzEIMUFjMuj/V5coRi4MoZxkcUliKtRjGMMXhNx+XoUExhXeNyI4+rNOK4NUVwXMUkxPHnDxU2IEYqhkSmKURHDcUxjjIyJGIUYlzExPcZi3MXExAzFpIjJqTimpmcxpr2YiQJEvDUzK2IW4haFB/xoRUo2Njb2paJIbty4UaRk8N8hWN41NFigGySXwyojUMk08ge6QXI5rDIClUwjf6AbJJfDKiNQyTTyB7pBcjmsMgKVTCN/oBskl8MqI1DJNPIHukFyOawyApVMI3+gGySXwyojUMk08ge6QXI5rDKCwiQbGZvycpqKvex7sQ1d+4dG+jYt6ehY8uqxRGUWps7iLX2JfBPQZ1aRRiGBbpBcDquMoDDJxsYnxsYnvczGw0hmxPLz64VKtpCBbpBcDquMoEjJgNyeqWRVDHSD5HJYZQRFSvb+++8PDAzk8yxNMl8gU4dYubduna79QrJ9Kym/o2P5PqqsMcdAN0guh1VGUKRk3d3dDz/8cD7P6krGKxzb8m13r5aoE93DWauoqPfVxR3f3tRr83tf3aSSFRToBsnlsMoICpbs3nvvzedZvAJZ7GLDBDKWRKsXxP7lJI1Xx5lkI17J/OYaxQS6QXI5rDKCgiVbtmzZ8uXLc3hWZyVjm12EL6KpI0yKJbPVAJfUKCbQDZLLYZURFCzZY489dv369RyeNSBZ6lLUoGQYsP5FdmoUEOgGyeWwygiKl2x0dPTpp5++//77T548OTo2MTzq10yNOpIltkIXNeqwIhbmfs4fSCNnoBskl8MqIyhYMljDchgGUUcyrBC/MNu3qSt5428eR3WMTNH+uG9ltHqlDaSRM9ANksthlREUf+OfwzCIupKRQw4nTWYdyIQ+qcgsco46byFoNBHoBsnlsMoICpYsn2EaFQ10g+RyWGUERUq2e/duNaytAt0guRxWGUGRkgFqWFsFukFyOawygiIlU8PaLdANksthlREUKJk5oeplarR2oBskl8MqIyhMMo02DHSD5HJYZQQqmUb+QDdILodVRqCSaeQPdIPkclhlBCqZRv5AN0guh1VGoJJp5A90g+RyWGUEKplG/kA3SC6HVUbQhGSKkqRgyfgX/GloQKAbJJfDKiPQ7VIjf6AbJJfDKiNQyTTyB7pBcjmsMgKVTCN/oBskl8MqI1DJNPIHukFyOawyApVMI3+gGySXwyojUMk08ge6QXI5rDIClUwjf6AbJJfDKiNQyTTyB7pBcjmsMoLgko2PT3g5qWFOK6WfrKxVlB3eKaacEZ930kgLdIPkclhlBGElA8MALzM1rElpJyLpNFsDku1bKQ5mqmThA90guRxWGUFAycCwgYGBxiVb3LUy+bUo9gt8vp1xfFyGSjbvgW6QXA6rjCCUZGDY4cOHn3zyySYk27I/YYb99p59/ncU0LJnIClZDi6HJFmU77mC58sRryjuSr/hrF6gGySXwyojCCIZGvbd7373sccea0ayPrkaucVJfsmFkcDtquyLylJWstgG44fsIV4yzbewRCaZIt5hVMSvQb/hzAW6QXI5rDKC4iWLDLv33nublsxOOf8KAvNYTnDGF5WlSRbf4bHdUyprwshk+0wUuatKjqthAt0guRxWGUHBknHDcknGvnUnmlc+93Z18YiXKykZ+eElI6WiiPpPFMWSobWJvbXNA90guRxWGUGRknmGATkkixYnuYpwyTJWlLCSYZiFNta67QPdILkcVhlBYZIlDQNySYaPX433QS4Zf+xFg5Ile4ga+kVeJxTxWtv2gW6QXA6rjKAYycCw0dHRHTt2dEv++te/5pDMTja7o5JzDzWFTPRFZd46lC2Z34N/FxgV4TNQaqXfcJYW6AbJ5bDKCAqQbGx8asz8pYjM8OqnhpDMTna8JaUtMBFs53L5xgBhVSJpRXHIvS/uHOrHV4XeI7Gg7R7oBsnlsMoICr7x12irQDdILodVRqCSaeQPdIPkclhlBCqZRv5AN0guh1VGoJJp5A90g+RyWGUEKplG/kA3SC6HVUagkmnkD3SD5HJYZQQqmUb+QDdILodVRqCSaeQPdIPkclhlBCqZRv5AN0guh1VGoJJp5A90g+RyWGUETUimKElUMiU4KpkSHJVMCU5lJBt2UFqpDhWQDN26cOHCkW1H8DFAZUoVKLVk6BPota3zCARItq0T/hdEtY9WdXyn+5x9eK77Ox1RohlMwzztWp3ySgYOkV7bjgBo1ZUrVw4cOACqwX8xh2rPGSZZblSydEotGejV+S2zdIFbqBQAjyEH8jFJteeMShaOsksGPtEuecSoBv+Fx5AP/527ZCAWseojb7uMXYkrQS1IU2mcHVeVDU3KYVsCppV7bDB1eLo1KbtkuC2ePn0axULbTFEnbaBUu3nMfEdGWGVcirnCtTnX3e0kY9rYJCV4bUis4r1TFWmZadD6jlVEMgTEAtuix/iAajeL8MEAs58hmWeByRJ5sTeJTh2sc25ZSu8tSbtKJlcUIF0yVEo810yYFGf4RWYQR5Qfj8yGbG1KLRnegR0+fBh9QsncE8z5kQwhW2yDVMmwK15km7gRhE5QyyZEZktTaskAUAp8giXN3JZ1gnXmMQSWUtUc+KrwtF+GmFwjTaI0loUVGcdiiaVPUA1S7eNYiSVDUCZc0jq/Fd/4A1QjJ0aIaJZtQqTo8UerIlOcNrKuzU5pyB7aKnEDAAoBkdXSlF0yBK2KXjCj3LmCuhhgutnC4rniYFnf6f6ItzXZBtaQNxWvj1hsWbzQtTrVkAxAzwBKLxjCpJyYPtrHsepIVhrmLlmbrWMqWfPMSTJ7e9ZehgEqmRIclUwJjkqmBEclU4KjkinBUcmU4KhkSnAqIxm93r/wr/grTVMBydAtPRJXXUotGfo0P0ficoAv3/uv3vtvhisllgwcms8jcQ0hBaL3iDylVLIEpZYM9Jq3I3ENkZRsVbf/VqZKlqDskoFPtEvO35E4Q1zk9kOWQ3kmBx6Y/5PqRSn7eQsi3lbxLfboE2m2dlxTbL/Jy6giZZcMt8X5PRJnU25OxYcuuECsGq/P66SfiiOhqJLtH2CprDZs6GpRDckQEGs+jsSZokgZgFnDHgJMAvkwzQaWLcc2qXi8uKzGZVSNdpWMWYHEc2iKfFIF4n3EqiTrOFy2lCzZAFO8pUNccXUotWR4BzbfR+ISRTFxJYOs6NSRHUUVWNPGJauoVD6llgwApcAnWNLm70icX8RI+CA0wIbd6Zawpo1JVuMyqkZ5JUNQJlzS5utInNUjnt+M23c/ZTA5UUfcElvAR4u7N2XpKdMoLmGXUTXKLhmCVkUvmFHuXEG1DDCVcqrjIoCJ5PJtlpFASpZiE1LjW4OyJcu+jIpRDckA9AygdMGY6azuLJacykgWFLtiqGOhaFvJxE7E9yulcHQlU4KjkinBUcmU4KhkSnBUMiU4KpkSHJVMCU5lJKPX+0O94q8EpAKSoVt6JK66lFoy9Km0R+IQ+dbBvL03ZYetyBsV5ZUMHCr5kbjkTKNwoUTzR2fUKCoBpZYM9Cr7kbjE1FrPwmimkgWSDHyiXbJ0R+JMRppNUb5XwegXJ3HRQ2QuXEY0VnRJidGpZrLIG9UbdkEou2S4LZbxSFz25LlavBtANKh5Ws4lTUk0nhxdXpcoksNmX+b8UQ3JEBCrREfi5FxyXIlXI3O6Wa+mDqskm/DRvR9AFPFxMwedT9pVMk8APk2myIeq8rlM9BDhank1/Pnm47hepTq1TKpRxAaW+QtFqSXDO7CyHonLqhflexW4ZKaIJ1yvxUhmCm3Sy14oSi0ZAEqBT7CklfRIXKKiaU36mIdMMlOdkuwhwHr1xpZJMXqNIgBKIe3nLhTllQxBmXBJK9uROEzzeRSdyn5sVdeYGyL64AWATIrRaxQZoLg8f4iu7JIhaFX0ghnlzhUzTwjMBUyTN7sRbPZcPstCexh8YuPCVR+ZtsIRV8CGNtneZaRclemlRlGcwS5zIamGZAB6BlC6YMycFDIlbrYXeoIL+4EKoDKSBaVM/+wLoVw/UNtKFq04Fr7FVRzaocv0T0ZXMiU4KpkSHJVMCY5KpgRHJVOCo5IpwVHJlOBURjJ6vT/UK/5KQCogGbqlR+KqS6klQ5/KfCROvDve3Ivs9i2HOu80mDpRFRzLH4S9uz5nxHAFUl7JwKFyH4nz3x/8qLvw+UmRzLdAJZsLIBDoVd4jcaFmhJOQLOwfpWtXycAn2iUrcyTOkGzuphD/OBwMJWfUpBxxp0nJavxROu96TFuX5EMDtkE8oneF8YE8Pg4Q5/tNoh+Kcj3KLhlui2U8EuemKfmrzWjuVRcd1zghF9WJCngNdkkiG9vyfqKhbaepf5cOq8lWLpFxWdjEdZBBNSRDQKwSHYlD8JfMf82ZzW3VuCRxBQ42iKgD+a65fEg1WKaBX4ccS14IK5MFQNQl78wQjZpokka7SubNiD9ZPlQ1riTBJlgpszmbTYOXFO1cvqhjKrhLjuc2viReDpgqvDobK25jiFP+JcUZpm+ftB8qnVJLhndgpf0rcQIxH6nNvfngSdMmasQGEU1kx64oru0NbCq4pDc0GwGIU1411ofXd0yiSRqllgwApcAnWNJKeCRO4uYhs7lXwJJyCtkgook/0VgY/VE6m2blvLo3NBsBiFNeNVaUKHFkFnDKKxmCMuGSVq4jcdCGTantgdIZzb35YEleYhpHCdGED47YunFtPi4W5ZCMXTrvTyagZvoPlU7ZJUPQqugFM8qdK/g7NcCvSf7i4yLAd4myzK89RvymU5t78yGScYPsE3JmPCkZXUPcaXxJ8gSeNzQbAYhTWC16pYNXAuJrBDJ6TqcakgHoGUDpguFTohRMZSQLiv1Hqo6Fom0lE4t//RVfmQO6kinBUcmU4KhkSnBUMiU4KpkSHJVMCY5KpgSnMpLR6/2hXvFXAlIBydAtPRJXXUotGfoU6Ehc2vvNhRG/Uw20/ftV5ZUMHAp6JE5IJj+XMDf8N0LrH5UrcvQyUmrJQK9wR+JCSdbQh18kKtnCSgY+0S5Z9JG4SDLzIMJpxzIjE1GfugfLoo5TSHabOnqLUXbJcFsMdSSOi8HWEl7EFiYUiiXSD5bJeoyMbv3RW49qSIaAWIWdVqohmZl/vqREZUIMVCmqJ8uoVKiW2a1KZmgzyUyBj63oiSTVSBUFu8JRMrvNaNtClFoyvAMLciQOJz1TsqiA07xkQNQos9vstq1CqSUDQCnwCZa0go/EeZPOp9lzKSaXZNE4md3WaNsilFcyBGXCJa3QI3HR5CcTNhXPetbxL6lGlIJabMEybVzPGd36o7ceZZcMQauiF8wod27ImbUyxHdJLmlxtRqTzHYcw6pkdAt4o7ca1ZAMQM8ASivVoTKSKdVFJVOCo5IpwVHJlOCoZEpwVDIlOCqZEhyVTAmOSqYEpzKS0ev9+op/BamAZOiWHomrLqWWDH0KdCROmTfKKxk4FPRI3MIgP7rRJpRaMtAr3JG4hUEls1ABYyElA59olwzwV+L4x7vY1NPnxuLPhUkt2OfFos9/YRP2x9J4166W+KAZ/5CaI3ENdf76WlUou2S4LYY6EhdbYlJuMmnehQZcFF5AbbBJbEPmx14hxZypdw2sapWphmQIiFXYaSUmCBHLIKwyREWmxCvAThJNGFElP9HUNVSZdpUsnk5HPOWJyY8yTCsf20vSF1E3LuKSNXENvDNskswpL6WWDO/A5uevxGVPMGbYyslWRJoTriIk4iKeaOoaqkypJQNAKfAJlrSCj8QlJzGe/kRZVJQ59bJA2sO9EommrqHKlFcyBGXCJa34I3Fi8iMvzASzMlFRtso4LcdTpgEr4uP4vfEylSyNQJIhaFX0ghnlzhkrAMH2LZzgOf2xtLiS/yf0XYlrWfMaVDJJUMkA9AygdEBaaoLLQGUkm0dUsoJRyZKoZAWjkinBUcmU4KhkSnAKk+znq7smJycooSiMwiRb//yay4OXKKEojtmZmVVPPEpyOaiM0ZBkWze/1NeX0lhpc65fv/aL//g3kstBZYyGJNv7t90f7n+XEori+Pzood++spHkclAZoyHJYBmDxYwSiuJ46w+//8tfdpNcDipjNCQZ8PKLz/T3n6eEoty5MzI8BHtlb08PyeWgYkajkn355ee/695KCUW5c+fPe3bu2vVHMotBxYxGJQNAMlCNEkp7c+7s6V+9/FxyGQOoBqMJyeD5qm6aCgBPKn/5/NP/+/lR0opx6tQpqsRoQjIAev/1xud1PWtnYJV5+aVnP/nkY9JKQpUkzUkGTEyMw765/c3X4L6PspT2AKYe7sNefOEXhw//k5ySnDx5kqpKmpYM+fzoobXPrAbbDh06qBtoa3N58BJMNywrz/znv8Odfup9GEINEuSUDIBbNNg33/rD79evW7NyxVKNVo21z67+7Ssb9/7tv/71ry/IpjRIizTySxYxODhI4yjtysDAANmQRgGSIX19fTSg0maQAdkUJhkASxrc+tHIShtw8eJFmvuaFCkZB4Y/r7QitXfGVEJJpigRKpkSHJVMCY5KpgRHJVOCo5Ipgblz5/8BRVikB1hUDrEAAAAASUVORK5CYII=)

A constructor that receives a reference to an unmodifiable string, extracts 4 tokens from the string, populates the object with those tokens and determines the field width to be used in displaying data for all objects of the class.


A constructor that receives a reference to an unmodifiable string, extracts 4 tokens from the string, populates the object with those tokens and determines the field width to be used in displaying data for all objects of the class.
- **const**** std::string&amp; **** getName() **** const**– a query that returns a reference to the name of the item
- **const**** unsigned int **** getSerialNumber() **** const**– a query that returns the serial number of the item
- **const**** unsigned int **** getQuantity() **** const**– a query that returns the remaining number of items in the set
- **ItemSet**** &amp; **** operator--****()**– a prefix decrement operator that reduces the number of items in stock by one and increases the serial number by one. This operator returns a reference to the current object.
- **void** **display(std::****ostream ****&amp; os,**  **bool full**** ) **** const **– a query that receives a reference to an** std::ostream **object** os **and a Boolean** full **and inserts the data for the current object into stream** os **. If the Boolean is** false **the data consists of the name of the items in the set and the next serial number to be assigned. If the Boolean is** true**, the data consists of the name, serial number quantity in stock and the description of the items in the set (as shown above). The field width for the name is just large enough to display the largest name. The field width for the serial number is 5 with &#39;0&#39; fill and the field width for the quantity in stock is 3 left-justified. Fields are separated by a single blank character.

Your design disables copy and move assignment operations and copy construction of the list.


