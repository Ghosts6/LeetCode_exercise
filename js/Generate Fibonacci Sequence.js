function* fibGenerator() {
    let prev = 0;
    let curr = 1;

    while (true) {
        yield prev;
        [prev, curr] = [curr, prev + curr];
    }
}