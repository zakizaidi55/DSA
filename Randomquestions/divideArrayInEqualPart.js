function divideArray(nums: number[]): boolean {
    let arr = new Array(501).fill(0);
    for(let num of nums) 
        arr[num]++;
    return arr.every(e => e % 2 === 0)
};


