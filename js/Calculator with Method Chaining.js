class Calculator {
    /**
     * @param {number} value
     */
    constructor(value) {
        this.result = value;
    }

    /**
     * @param {number} value
     * @returns {Calculator}
     */
    add(value) {
        this.result += value;
        return this;
    }

    /**
     * @param {number} value
     * @returns {Calculator}
     */
    subtract(value) {
        this.result -= value;
        return this;
    }

    /**
     * @param {number} value
     * @returns {Calculator}
     */
    multiply(value) {
        this.result *= value;
        return this;
    }

    /**
     * @param {number} value
     * @returns {Calculator}
     */
    divide(value) {
        if (value === 0) {
            throw new Error("Division by zero is not allowed");
        }
        this.result /= value;
        return this;
    }

    /**
     * @param {number} value
     * @returns {Calculator}
     */
    power(value) {
        this.result **= value;
        return this;
    }

    /**
     * @returns {number}
     */
    getResult() {
        return this.result;
    }
}