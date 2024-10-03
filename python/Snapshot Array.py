from collections import defaultdict
import bisect

class SnapshotArray:

    def __init__(self, length: int):
        self.snapshots = defaultdict(list)  
        self.current_snap_id = 0            
        self.arr = [0] * length            

        for i in range(length):
            self.snapshots[i].append((self.current_snap_id, 0))

    def set(self, index: int, val: int) -> None:
        if self.snapshots[index] and self.snapshots[index][-1][0] == self.current_snap_id:
            self.snapshots[index][-1] = (self.current_snap_id, val)
        else:
            self.snapshots[index].append((self.current_snap_id, val))

    def snap(self) -> int:
        self.current_snap_id += 1
        return self.current_snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        snaps = self.snapshots[index]
        i = bisect.bisect_right(snaps, (snap_id, float('inf'))) - 1
        return snaps[i][1]


# Test case
if __name__ == "__main__":
    snapshotArr = SnapshotArray(3)   #
    snapshotArr.set(0, 5) 
    print(snapshotArr.snap())       
    snapshotArr.set(0, 6)            
    print(snapshotArr.get(0, 0))