typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t cond1;
    pthread_cond_t cond2;
    int state;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    pthread_mutex_init(&obj->lock, NULL);
    pthread_cond_init(&obj->cond1, NULL);
    pthread_cond_init(&obj->cond2, NULL);
    obj->state = 0;
    
    return obj;
}

void first(Foo* obj) {
    pthread_mutex_lock(&obj->lock);
    printFirst();
    
    obj->state = 1;
    pthread_cond_signal(&obj->cond1);
    pthread_mutex_unlock(&obj->lock);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->lock);

    while (obj->state < 1) {
        pthread_cond_wait(&obj->cond1, &obj->lock);
    }
    printSecond();
    
    obj->state = 2;
    pthread_cond_signal(&obj->cond2);
    pthread_mutex_unlock(&obj->lock);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->lock);

    while (obj->state < 2) {
        pthread_cond_wait(&obj->cond2, &obj->lock);
    }
    printThird();
    
    pthread_mutex_unlock(&obj->lock);
}

void fooFree(Foo* obj) {
    pthread_mutex_destroy(&obj->lock);
    pthread_cond_destroy(&obj->cond1);
    pthread_cond_destroy(&obj->cond2);
    free(obj);
}