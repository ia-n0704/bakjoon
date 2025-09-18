function test() {
    setTimeout(() => console.log("하나"),1000);
    setTimeout(() => console.log("둘"),999);
    setTimeout(() => console.log("셋"),998);
}
test()