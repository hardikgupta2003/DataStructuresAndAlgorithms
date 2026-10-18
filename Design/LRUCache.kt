import java.util.LinkedHashMap

// Approach 1: Using Kotlin/Java LinkedHashMap
class LRUCacheUsingLinkedHashMap<K : Any, V : Any>(
    private val capacity: Int
) {
    private val cache = LinkedHashMap<K, V>(
        16, 0.75f, true
    )

    init {
        require(capacity > 0) { "Capacity must be positive" }
    }

    /** Returns the value and marks the key as recently used. */
    fun get(key: K): V? {
        return cache[key]
    }

    /** Inserts or updates a value and removes the LRU entry if full. */
    fun put(key: K, value: V) {
        cache[key] = value

        if (cache.size > capacity) {
            val oldestKey = cache.keys.iterator().next()
            cache.remove(oldestKey)
        }
    }

    /** Returns the current number of entries. */
    fun size(): Int = cache.size
}


// Approach 2: Custom LRU using HashMap + Doubly Linked List
class LRUCacheCustom<K : Any, V : Any>(
    private val capacity: Int
) {
    // Each node stores a key, value and links to its neighbours.
    private class Node<K : Any, V : Any>(
        var key: K? = null,
        var value: V? = null
    ) {
        var prev: Node<K, V>? = null
        var next: Node<K, V>? = null
    }

    private val cache = HashMap<K, Node<K, V>>()

    // Head = most recently used, tail = least recently used.
    private val head = Node<K, V>()
    private val tail = Node<K, V>()

    init {
        require(capacity > 0) { "Capacity must be positive" }

        head.next = tail
        tail.prev = head
    }

    /** Removes a node from its current position in the list. */
    private fun removeNode(node: Node<K, V>) {
        val before = node.prev!!
        val after = node.next!!

        before.next = after
        after.prev = before
    }

    /** Adds a node immediately after the head. */
    private fun addToFront(node: Node<K, V>) {
        val first = head.next!!

        node.prev = head
        node.next = first

        head.next = node
        first.prev = node
    }

    /** Marks an existing node as the most recently used. */
    private fun moveToFront(node: Node<K, V>) {
        removeNode(node)
        addToFront(node)
    }

    /** Returns the value and marks the key as recently used. */
    fun get(key: K): V? {
        val node = cache[key] ?: return null

        moveToFront(node)
        return node.value
    }

    /** Inserts or updates a value and evicts the least used entry if full. */
    fun put(key: K, value: V) {
        val existingNode = cache[key]

        // If the key exists, update its value and move it to the front.
        if (existingNode != null) {
            existingNode.value = value
            moveToFront(existingNode)
            return
        }

        // Otherwise, create a new node and add it to the front.
        val newNode = Node(key, value)
        cache[key] = newNode
        addToFront(newNode)

        // If capacity is exceeded, remove the node before the tail.
        if (cache.size > capacity) {
            val leastRecentlyUsed = tail.prev!!
            removeNode(leastRecentlyUsed)
            cache.remove(leastRecentlyUsed.key!!)
        }
    }

    /** Returns the current number of entries. */
    fun size(): Int = cache.size
}


// Driver code: test both implementations.
fun main() {
    println("=== LinkedHashMap Implementation ===")

    val cache1 = LRUCacheUsingLinkedHashMap<String, Int>(3)

    cache1.put("A", 10)
    cache1.put("B", 20)
    cache1.put("C", 30)

    println(cache1.get("A"))  // 10; A becomes recently used

    cache1.put("D", 40)       // B is evicted

    println(cache1.get("B"))  // null
    println(cache1.get("C"))  // 30
    println(cache1.size())    // 3

    println("\n=== Custom Implementation ===")

    val cache2 = LRUCacheCustom<String, Int>(3)

    cache2.put("A", 10)
    cache2.put("B", 20)
    cache2.put("C", 30)

    println(cache2.get("A"))  // 10; A becomes recently used

    cache2.put("D", 40)       // B is evicted

    println(cache2.get("B"))  // null
    println(cache2.get("C"))  // 30
    println(cache2.size())    // 3
}