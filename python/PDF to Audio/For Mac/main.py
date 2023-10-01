import PyPDF2
import pyttsx3

#initialising the pyttsx3 module
engine = pyttsx3.init()

file_path = "" #enter the location of the file

#opening the pdf file
pdfReader = PyPDF2.PdfReader(open(file_path, "rb"))

print("The number of pages in the pdf : ",len(pdfReader.pages))

print("\nContent of the pdf file is : \n")
for p in range(len(pdfReader.pages)):
    #accessing page number
    page = pdfReader.pages[p]

    #extracting the text from the file
    text = page.extract_text()

    #removing new line character from the text
    clean_text = text.strip().replace('\n', ' ')
    print(clean_text)

#converting the contents into an mp3 file
engine.save_to_file(clean_text,"demo.mp3")
engine.runAndWait()
