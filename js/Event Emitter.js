class EventEmitter {
    constructor() {
        this.events = new Map();
    }
    
    subscribe(eventName, callback) {
        if (!this.events.has(eventName)) {
            this.events.set(eventName, []);
        }
        const subscribers = this.events.get(eventName);
        subscribers.push(callback);
        
        return {
            unsubscribe: () => {
                const index = subscribers.indexOf(callback);
                if (index !== -1) {
                    subscribers.splice(index, 1);
                }
            }
        };
    }
    
    emit(eventName, args = []) {
        if (!this.events.has(eventName)) {
            return [];
        }
        
        const subscribers = this.events.get(eventName);
        return subscribers.map(callback => callback(...args));
    }
}