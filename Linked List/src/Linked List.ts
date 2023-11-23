type Lnode<T> = {
    data: T;
    next: Lnode<T> | null
}

type LinkedList<T> = Lnode<T> | null

function append<T>(list: LinkedList<T>, data:T): Lnode<T> {
    if (!list) {
        return {data, next: null}
    }

    return {data: list.data, next: append(list.next, data)}
} 

function remove<T>(list:  LinkedList<T>, data: T): LinkedList<T> {
   if (!list) {
        return null
   }

   if (list.data === data) {
        return list.next;
   }

   return {data: list.data, next: remove(list.next, data)}
}

function display<T>(list: LinkedList<T>): void {
    if (list) {
        console.log(list.data)
        display(list.next)
    }
}
