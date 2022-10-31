// program to merge and remove duplicate value from an array

function getUniqueAfterMerge(arr1, arr2){

    // merge two arrays

    let arr = arr1.concat(arr2);

    let uniqueArr = [];

    // loop through array

    for(let i of arr) {

        if(uniqueArr.indexOf(i) === -1) {

            uniqueArr.push(i);

        }

    }

    console.log(uniqueArr);

}

const array1 = [1, 2, 3];

const array2 = [2, 3, 5]

// calling the function

// passing array argument

getUniqueAfterMerge(array1, array2);
