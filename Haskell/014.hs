import Data.Time
import System.IO

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)

--solution :: Int
--solution = maxer 0 0 0 collSeq 
--solution = (length $ seq' 837799) + (length $ seq' 837799) + (length $ seq' 837799) + (length $ seq' 837799) + (length $ seq' 837799) 
solution = maxer 0 0 0 supseq

nextCollatz :: Int -> Int
nextCollatz n | n `mod` 2 == 0 = n `div` 2
              | otherwise = 3*n+1

--collatzSeq :: Int -> [Int] -> [Int]
--collatzSeq k (c:cs) = if next > k then collatzSeq 

-- Number to be evaluated -> Original number first passed -> Length so far -> List of lengths for predecessors -> Length for the number to be evaluted
collatzLenAux :: Int -> Int -> Int -> [Int] -> Int
collatzLenAux n o x cs = if next > o then collatzLenAux next o (x+1) cs else cs!!(len-next)+x+1
                         where next = nextCollatz n
                               len  = length cs

--collatzLen :: Int -> [Int] -> Int
--collatzLen n cs = collatzLenAux n n 0 cs

seq' :: Int -> [Int]
seq' 1 = [1]
seq' n = n : (seq' $ nextCollatz n)

--collatz :: Int -> [Int]
--collatz 1 = [1]
--collatz n = (collatzLen n cs):cs where cs = collatz (n-1)

supseq :: [Int]
supseq = 0:[length $ seq' n | n <- [1..1000000]]

--maxer :: Int -> (Int,Int) -> Int -> [Int] -> Int 
--maxer _ (n',s) o []     = o - n'
--maxer n (n',s) o (c:cs) = if c > s then maxer (n+1) (n,c) o cs else maxer (n+1) (n',s) o cs

--biggestSeq :: Int
--biggestSeq = maxer 0 (0,0) (length cs) cs where !cs = collatz 200000

--save :: Show a => a -> IO ()
--save x = writeFile "collatz.txt" (show x)

collAux :: Int -> Int -> Int -> Int
collAux n o s = if n < o then collSeq !! n + s else collAux (nextCollatz n) o (s+1)

collSeq :: [Int]
collSeq = 0:1:(map lenColl [2..1000000])
  where lenColl n = collAux n n 0

maxer :: Int -> Int -> Int -> [Int] -> Int
maxer m pm pc []     = pm
maxer m pm pc (l:ls) = if l > m then maxer l pc (pc+1) ls else maxer m pm (pc+1) ls
