const containsDuplicates = arr => {
    seen = {}
    for (n in arr) {
        if (seen[n] === undefined) return true;
        seen[n] = true;
    }
    return false;
}

const arr = [1,2,3,1];
console.log(containsDuplicates(arr));