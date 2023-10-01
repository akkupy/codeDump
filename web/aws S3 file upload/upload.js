import React, { useState } from 'react';
import AWS from 'aws-sdk';
import Swal from 'sweetalert2';

const UploadImage = () => {
  const [selectedFile, setSelectedFile] = useState(null);

  const handleFileInput = (e) => {
    setSelectedFile(e.target.files[0]);
  };

  const handleUpload = () => {
   
    AWS.config.update({
      accessKeyId: '',
      secretAccessKey: '',
      region: '',
    });

    const s3 = new AWS.S3();
    const fileName = selectedFile.name;
    const fileType = selectedFile.type;

   
    const bucketName = '';
    const objectKey = `${Date.now()}-${fileName}`;

    
    const params = {
      Bucket: bucketName,
      Key: objectKey,
      Body: selectedFile,
      ContentType: fileType,
      ACL: 'public-read',
    };

    
    s3.upload(params, (err, data) => {
      if (err) {
        console.log('Error uploading image: ', err);
      } else {
        console.log('Image uploaded successfully: ', data.Location);
        Swal.fire({
            icon: 'success',
            title: 'Image uploaded successfully',
            text: data.Location,
            });
            setSelectedFile(null);

      }
    });
  };

  return (
    <div className="max-w-lg mx-auto my-8">
      <div className="flex flex-col items-center justify-center border-4 border-dashed border-gray-400 h-64 w-full rounded-lg">
        {selectedFile ? (
          <img
            className="object-contain h-48 rounded-md"
            src={URL.createObjectURL(selectedFile)}
            alt="Selected file preview"
          />
        ) : (
          <div className="text-center">
            <p className="mb-2">Drag and drop an image here or click to select</p>
            <input
              type="file"
              className="hidden"
              onChange={handleFileInput}
              accept=".jpg,.jpeg,.png"
            />
            <button
              className="px-4 py-2 text-white bg-blue-500 rounded-md hover:bg-blue-600"
              onClick={() => document.querySelector('input[type="file"]').click()}
            >
              Select Image
            </button>
          </div>
        )}
      </div>
      {selectedFile && (
        <div className="text-center mt-4">
          <button
            className="px-4 py-2 text-white bg-green-500 rounded-md hover:bg-green-600"
            onClick={handleUpload}
          >
            Upload Image
          </button>
        </div>
      )}
    </div>
  );
};

export default UploadImage;
